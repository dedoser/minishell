/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:32:25 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/02 22:32:30 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	echo_com(t_com *com)
{
	int		arg;
	int		i;

	arg = 0;
	i = 0;
	while (com->args[++i])
	{
		if (!ft_strcmp(com->args[i], "-n"))
			arg = 1;
		else
		{
			write(com->out_fd, com->args[i], ft_strlen(com->args[i]));
			write(com->out_fd, " ", 1);
		}
	}
	if (!arg)
		write(com->out_fd, "\n", 1);
	errno = 0;
}

void	cd_com(t_com *com)
{
	if (chdir(com->args[1]))
		perror("");
}

void	pwd_com(t_com *com)
{
	char	*str;

	str = getcwd(NULL, 0);
	write(com->out_fd, str, ft_strlen(str));
	write(com->out_fd, "\n", 1);
	free(str);
	errno = 0;
}

void	env_com(t_com *com, t_envp *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, "?"))
		{
			write(com->out_fd, env->key, ft_strlen(env->key));
			write(com->out_fd, "=", 1);
			write(com->out_fd, env->value, ft_strlen(env->value));
			write(1, "\n", 1);
		}
		env = env->next;
	}
	errno = 0;
}

int		build_in(t_com *com, t_envp *envp)
{
	if (!ft_strcmp(com->args[0], "cd") ||
		!ft_strcmp(com->args[0], "/usr/bin/cd"))
		cd_com(com);
	else if (!ft_strcmp(com->args[0], "env") ||
			!ft_strcmp(com->args[0], "/usr/bin/env"))
		env_com(com, envp);
	else if (!ft_strcmp(com->args[0], "export"))
		export_com(com, envp);
	else if (!ft_strcmp(com->args[0], "unset"))
		unset_com(com, &envp);
	else if (!ft_strcmp(com->args[0], "echo") ||
			!ft_strcmp(com->args[0], "/bin/echo"))
		echo_com(com);
	else if (!ft_strcmp(com->args[0], "exit"))
		exit_com(com, envp);
	else
		return (0);
	return (1);
}
