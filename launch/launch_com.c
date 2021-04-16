/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 18:22:41 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

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
	res = (char **)malloc(sizeof(char *) * (i + 1));
	alloc_check(res);
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

static void	wait_child(t_envp *envp, int i)
{
	waitpid(g_var.child_pid[i], &g_var.status, WUNTRACED);
	if (WIFEXITED(g_var.status))
		change_errno(envp, WEXITSTATUS(g_var.status));
	else if (WIFSIGNALED(g_var.status))
	{
		change_errno(envp, 128 + WTERMSIG(g_var.status));
		write(1, "\n", 1);
	}
	else if (WIFSTOPPED(g_var.status))
	{
		write(1, "\n", 1);
		change_errno(envp, 128 + WSTOPSIG(g_var.status));
	}
}

static void	pipe_launch(t_com *com, t_envp *envp)
{
	int		i;

	g_var.child_pid = (pid_t *)malloc(sizeof(pid_t) * g_var.child_count);
	alloc_check(g_var.child_pid);
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
	signal(SIGINT, SIG_IGN);
	while (++i < g_var.child_count)
		wait_child(envp, i);
	tcsetattr(0, TCSANOW, &g_var.e_term);
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
