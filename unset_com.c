/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_com.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:50:34 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/02 22:25:13 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	delete_elem_envp(char *key, t_envp **envp)
{
	t_envp	*tmp;
	t_envp	*prev;

	tmp = *envp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (tmp == *envp)
			*envp = tmp->next;
		else
			prev->next = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

void	unset_com(t_com *com, t_envp **envp)
{
	int		i;

	i = 0;
	while (com->args[++i])
		delete_elem_envp(com->args[i], envp);
}
