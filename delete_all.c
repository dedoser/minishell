/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:33:09 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/14 20:07:47 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	delete_list(t_arg *str)
{
	t_arg	*tmp;

	while (str)
	{
		tmp = str;
		str = str->next;
		free(tmp->line);
		free(tmp);
	}
}

void	delete_mass(char **mass)
{
	int		i;

	i = -1;
	if (!mass)
		return ;
	while (mass[++i])
		free(mass[i]);
	free(mass);
}

void	delete_envp(void)
{
	t_envp	*tmp;

	while (g_var.envp)
	{
		free(g_var.envp->key);
		free(g_var.envp->value);
		tmp = g_var.envp;
		g_var.envp = g_var.envp->next;
		free(tmp);
	}
}

void	delete_com(t_com **com)
{
	int		i;
	t_com	*tmp;
	t_com	**mass;

	i = 0;
	mass = com;
	while (mass[i])
	{
		free(mass[i]->line);
		while (com[i])
		{
			delete_list(mass[i]->list);
			delete_mass(com[i]->args);
			delete_list(com[i]->in_files);
			delete_list(com[i]->out_files);
			tmp = com[i];
			com[i] = com[i]->next;
			free(tmp);
		}
		++i;
	}
	free(mass);
	// delete_envp();
}
