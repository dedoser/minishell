/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/02 23:13:53 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	change_errno(t_envp *envp, int err)
{
	while (envp)
	{
		if (!ft_strcmp(envp->key, "?"))
			break ;
		envp = envp->next;
	}
	free(envp->value);
	envp->value = ft_itoa(err);
}

char	**make_mass_envp(t_envp *envp)
{
	t_envp	*tmp;
	int		i;
	char	**res;

	tmp = envp;
	i = 0;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	if (!(res = (char **)malloc(sizeof(char *) * (i + 1))))
		exit_error("Malloc error");
	i = 0;
	while (envp)
	{
		res[i] = ft_strcat(ft_strfcat(envp->key, "="), envp->value);
		++i;
		envp = envp->next;
	}
	res[i] = NULL;
	return (res);
}

void	redirect_fd(t_com *com)
{
	if (com->in_fd != 0)
	{
		close(g_var.prev_fd);
		dup2(com->in_fd, 0);
	}
	if (com->out_fd != 1)
	{
		close(g_var.next_fd);
		dup2(com->out_fd, 1);
	}
}

void	fork_start(t_com *com, t_envp *envp)
{
	pid_t	t_pid;

	t_pid = fork();
	if (t_pid == -1)
	{
		write(2, "Fork error\n", 11);
		close(g_var.fd[0]);
		close(g_var.fd[1]);
	}
	else if (t_pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if (g_var.cur_child == 1)
			g_var.prev_fd = 0;
		if (g_var.cur_child == g_var.child_count)
			g_var.next_fd = 1;
		dup2(g_var.prev_fd, 0);
		dup2(g_var.next_fd, 1);
		redirect_fd(com);
		execve(com->args[0], com->args, make_mass_envp(envp));
		printf("beautiful_shell: %s: command not found\n", com->args[0]);
		exit(errno);
	}
	else
	{
		signal(SIGTSTP, SIG_IGN);
		g_var.child_pid[g_var.cur_child - 1] = t_pid;
		g_var.prev_fd = g_var.fd[0];
		if (g_var.next_fd != 1)
			close(g_var.next_fd);
	}
	return ;
}

void	pipe_launch(t_com *com, t_envp *envp)
{
	int		i;

	if (!(g_var.child_pid = (pid_t *)malloc(sizeof(pid_t) * g_var.child_count)))
		exit_error("Malloc error");
	while (com)
	{
		if (pipe(g_var.fd) == -1)
		{
			write(2, "Pipe error\n", 11);
			return ;
		}
		g_var.next_fd = g_var.fd[1];
		fork_start(com, envp);
		g_var.cur_child++;
		com = com->next;
	}
	i = -1;
	while (++i < g_var.child_count)
	{
		waitpid(g_var.child_pid[i], &g_var.status, WUNTRACED);
		change_errno(envp, WEXITSTATUS(g_var.status));
	}
	free(g_var.child_pid);
}

void	launch_com(t_com *com, t_envp *envp)
{
	t_com	*tmp;
	int		i;

	i = 0;
	tmp = com;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	if (i == 1)
	{
		if (!build_in(com, envp))
		{
			g_var.cur_child = 1;
			g_var.child_count = i;
			pipe_launch(com, envp);
		}
	}
	else
	{
		g_var.cur_child = 1;
		g_var.child_count = i;
		pipe_launch(com, envp);
	}
}
