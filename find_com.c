/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:18:49 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/27 19:31:42 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

//мб надо проверять closedir на ошибку
int		is_com_in_path(t_com *com, char *path)
{
	struct dirent	*file;
	DIR				*dir;

	if (!(dir = opendir(path)))
		return (0);
	while ((file = readdir(dir)) != NULL)
	{
		if (!ft_strcmp(com->args[0], file->d_name))
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

void	free_split(char **mass)
{
	int	i;

	i = -1;
	while (mass[++i])
		free(mass[i]);
	free(mass);
}

void	find_com(t_com *com, t_envp *env)
{
	char	**var;
	int		i;
	int		is_find;

	while (env)
	{
		if (!ft_strcmp(env->key, "PATH"))
			break ;
		env = env->next;
	}
	if (env == NULL)
		return ;
	var = ft_split(env->value, ':');
	i = -1;
	while (var[++i])
	{
		if ((is_find = is_com_in_path(com, var[i])))
			break ;
	}
	if (is_find)
		com->args[0] = ft_strcat(ft_strfcat(var[i], "/"), com->args[0]);
	free_split(var);
}
