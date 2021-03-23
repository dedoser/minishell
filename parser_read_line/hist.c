/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:09 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/23 19:06:22 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

void	ret_envp(t_envp **envp, char *str)
{
	char	**mass;
	t_envp	*res;
	t_envp	*tmp;

	mass = ft_split(str, '=');
	if (!(res = (t_envp *)malloc(sizeof(t_envp))))
		exit_error("Malloc error");
	res->key = mass[0];
	res->value = mass[1];
	res->next = NULL;
	free(mass);
	if (*envp == NULL)
		*envp = res;
	else
	{
		tmp = *envp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = res;
	}
}

void	copy_envp(t_hist *hist, char **envp)
{
	int	i;

	hist->envp = NULL;
	i = -1;
	while (envp[++i])
		ret_envp(&hist->envp, envp[i]);
}
