/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_build_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:42:25 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:39:21 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/build_in.h"

static int	check_key(char *key, t_envp *envp)
{
	int		i;

	if (!key)
		return (0);
	i = -1;
	while (key[++i])
		if (!ft_isalpha(key[i]) && key[i] != '_')
			return (0);
	while (envp)
	{
		if (!ft_strcmp(envp->key, key))
			return (-1);
		envp = envp->next;
	}
	return (1);
}

static int	add_exist(char **key_val, t_envp *envp, int res)
{
	if (!res)
	{
		write(2, "not a valid identifier\n", 23);
		errno = 2;
		return (1);
	}
	free(envp->value);
	envp->value = key_val[1];
	return (0);
}

static int	add_to_envp(char *str, t_envp *envp)
{
	char	**key_val;
	int		res;
	int		status;

	key_val = ft_split_envp(str, '=');
	res = check_key(key_val[0], envp);
	status = 0;
	while (envp->next)
		envp = envp->next;
	if (res > 0)
	{
		envp->next = (t_envp *)malloc(sizeof(t_envp));
		alloc_check(envp->next);
		envp = envp->next;
		envp->key = key_val[0];
		envp->value = key_val[1];
		envp->next = NULL;
	}
	else
		status = add_exist(key_val, envp, res);
	free(key_val);
	return (status);
}

static int	export_add(t_com *com, t_envp *envp)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
	while (com->args[i])
	{
		res += add_to_envp(com->args[i], envp);
		++i;
	}
	return (res);
}

int	export_com(t_com *com, t_envp *env)
{
	int	res;

	if (count_args(com) == 1)
	{
		export_out(env);
		return (0);
	}
	else
	{
		res = export_add(com, env);
	}
	return (res != 0);
}
