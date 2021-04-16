/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:47:37 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:22:53 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

static void	signal_child(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
}

static void	child_fork(t_com *com, t_envp *envp)
{
	char	**envp_mass;

	signal_child();
	set_fd(com);
	tcsetattr(0, TCSANOW, &g_var.term);
	envp_mass = make_mass_envp(envp);
	if (!build_in(com, envp))
		execve(com->args[0], com->args, envp_mass);
	else
		exit(0);
	write(2, "beautiful shell: ", 17);
	write(2, com->args[0], ft_strlen(com->args[0]));
	write(2, ": command not found\n", 20);
	delete_mass(envp_mass);
	delete_com(g_var.com);
	exit(127);
}

static void	fork_father(pid_t t_pid)
{
	signal(SIGTSTP, SIG_IGN);
	g_var.child_pid[g_var.cur_child - 1] = t_pid;
	if (g_var.prev_fd != 0)
		close(g_var.prev_fd);
	g_var.prev_fd = g_var.fd[0];
	if (g_var.next_fd != 1)
		close(g_var.next_fd);
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
		child_fork(com, envp);
	else
		fork_father(t_pid);
	return ;
}
