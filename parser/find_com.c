/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:18:49 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:32:16 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	is_com_in_path(t_com *com, char *path)
{
	struct dirent	*file;
	DIR				*dir;

	dir = opendir(path);
	if (!dir)
		return (0);
	while (1)
	{
		file = readdir(dir);
		if (!file)
			break ;
		if (!ft_strcmp(com->args[0], file->d_name))
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

static void	free_split(char **mass)
{
	int	i;

	i = -1;
	while (mass[++i])
		free(mass[i]);
	free(mass);
}

static int	find_in_path(t_com *com, char **var, int *i)
{
	int	is_find;

	*i = -1;
	while (var[++(*i)])
	{
		is_find = is_com_in_path(com, var[*i]);
		if (is_find)
			break ;
	}
	return (is_find);
}

void	find_com(t_com *com, t_envp *env)
{
	char	**var;
	int		is_find;
	char	*arg;
	int		i;

	while (env)
	{
		if (!ft_strcmp(env->key, "PATH"))
			break ;
		env = env->next;
	}
	if (env == NULL)
		return ;
	var = ft_split(env->value, ':');
	is_find = find_in_path(com, var, &i);
	arg = com->args[0];
	if (is_find)
	{
		com->args[0] = ft_strcat(ft_strfcat(var[i], "/"), com->args[0]);
		free(arg);
	}
	free_split(var);
}
