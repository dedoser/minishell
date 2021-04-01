/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_build_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:42:25 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/01 17:16:52 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		count_args(t_com *com)
{
	int		i;

	i = 0;
	while (com->args[i])
		++i;
	return (i);
}

int		check_key(char *key)
{
	if (!key)
		return (0);
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	return (1);
}

void	add_to_envp(char *str, t_envp *envp)
{
	char	**key_val;

	while (envp->next)
		envp = envp->next;
	key_val = ft_split_envp(str, '=');
	if (check_key(key_val[0]))
	{
		if (!(envp->next = (t_envp *)malloc(sizeof(t_envp))))
			exit_error("Malloc error");
		envp = envp->next;
		envp->key = key_val[0];
		envp->value = key_val[1];
		envp->next = NULL;
	}
	else
	{
		write(2, "not a valid identifier\n", 23);
		errno = 2;
	}
}

void	export_add(t_com *com, t_envp *envp)
{
	int		i;

	i = 1;
	while (com->args[i])
	{
		add_to_envp(com->args[i], envp);
		++i;
	}
}

void	export_com(t_com *com, t_envp *env)
{
	if (count_args(com) == 1)
		export_out(env);
	else
		export_add(com, env);
}
