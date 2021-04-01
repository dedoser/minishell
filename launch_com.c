/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/01 22:01:15 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

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
		signal(SIGTSTP, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		free(g_var.child_pid);
		dup2(com->in_fd, 0);
		dup2(com->out_fd, 0);
		execve(com->args[0], com->args, make_mass_envp(envp));
		perror("");
		
	}
	return ;
}

void	pipe_launch(t_com *com, t_envp *envp)
{
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
	}
}

void	launch_com(t_com *com, t_envp *envp)
{
	t_com	*tmp;
	int		i;

	i = 0;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	if (i == 1)
		build_in(com, envp);
	else
	{
		g_var.cur_child = 1;
		g_var.child_count = i;
		pipe_launch(com, envp);
	}
}
