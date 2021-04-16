/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:32:25 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 18:09:59 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/build_in.h"

static void	change_oldpwd(char *str, t_envp *envp)
{
	t_envp	*prev;
	char	*tmp;

	while (envp)
	{
		if (!ft_strcmp(envp->key, "OLDPWD"))
		{
			tmp = envp->value;
			envp->value = ft_strdup(str);
			free(tmp);
			return ;
		}
		prev = envp;
		envp = envp->next;
	}
	prev->next = (t_envp *)malloc(sizeof(t_envp));
	prev = prev->next;
	prev->key = ft_strdup("OLDPWD");
	prev->value = ft_strdup(str);
	prev->next = NULL;
}

static int	cd_com(t_com *com, t_envp *envp)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	change_oldpwd(oldpwd, g_var.envp);
	free(oldpwd);
	if (!com->args[1])
	{
		while (envp)
		{
			if (!ft_strcmp(envp->key, "HOME"))
			{
				chdir(envp->value);
				return (0);
			}
			envp = envp->next;
		}
		write(2, "beautiful shell: cd: HOME not set\n", 34);
		return (1);
	}
	else if (chdir(com->args[1]))
	{
		perror("");
		return (1);
	}
	return (0);
}

static int	pwd_com(t_com *com)
{
	char	*str;

	str = getcwd(NULL, 0);
	write(com->out_fd, str, ft_strlen(str));
	write(com->out_fd, "\n", 1);
	free(str);
	return (0);
}

static int	env_com(t_com *com, t_envp *env)
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
	return (0);
}

int	build_in(t_com *com, t_envp *envp)
{
	int	res;

	res = 0;
	if (!ft_strcmp(com->args[0], "cd")
		|| !ft_strcmp(com->args[0], "/usr/bin/cd"))
		res = cd_com(com, envp);
	else if (!ft_strcmp(com->args[0], "env")
		|| !ft_strcmp(com->args[0], "/usr/bin/env"))
		res = env_com(com, envp);
	else if (!ft_strcmp(com->args[0], "export"))
		res = export_com(com, envp);
	else if (!ft_strcmp(com->args[0], "unset"))
		res = unset_com(com, &envp);
	else if (!ft_strcmp(com->args[0], "echo")
		|| !ft_strcmp(com->args[0], "bin/echo"))
		res = echo_com(com);
	else if (!ft_strcmp(com->args[0], "exit"))
		exit_com();
	else if (!ft_strcmp(com->args[0], "pwd")
		|| !ft_strcmp(com->args[0], "/bin/pwd"))
		pwd_com(com);
	else
		return (0);
	change_errno(envp, res);
	return (1);
}
