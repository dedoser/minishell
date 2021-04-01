/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:42:53 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/01 17:17:02 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		count_envp(t_envp *envp)
{
	int		i;

	i = 0;
	while (envp)
	{
		++i;
		envp = envp->next;
	}
	return (i);
}

char	**create_key_mass(t_envp *envp)
{
	char	**res;
	int		i;

	if (!(res = (char **)malloc(sizeof(char *) * (count_envp(envp) + 1))))
		exit_error("Malloc error");
	i = 0;
	while (envp)
	{
		res[i] = envp->key;
		++i;
		envp = envp->next;
	}
	res[i] = NULL;
	return (res);
}

char	**sort_key_mass(char **mass)
{
	int		ind;
	int		i;
	char	*tmp;

	ind = 1;
	while (ind)
	{
		ind = 0;
		i = 0;
		while (mass[i + 1])
		{
			if (ft_strcmp(mass[i], mass[i + 1]) > 0)
			{
				tmp = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = tmp;
				ind = 1;
			}
			++i;
		}
	}
	return (mass);
}

char	*find_envp(char *key, t_envp *envp)
{
	while (envp)
	{
		if (!ft_strcmp(key, envp->key))
			return (envp->value);
		envp = envp->next;
	}
	return (NULL);
}

void	export_out(t_envp *envp)
{
	char	**key_mass;
	int		i;

	key_mass = sort_key_mass(create_key_mass(envp));
	i = 0;
	while (key_mass[i])
	{
		printf("declare -x %s=\"%s\"\n",
				key_mass[i], find_envp(key_mass[i], envp));
		++i;
	}
	free(key_mass);
	errno = 0;
}
