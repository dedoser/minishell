/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:02:35 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/23 20:26:57 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

char	**submass(char **mass, int beg, int end)
{
	char	**res;
	int		i;

	if (!(res = (char **)malloc(sizeof(char *) * (end - beg + 1))))
		exit_error("Malloc error");
	i = 0;
	while (beg < end && mass[beg])
	{
		res[i] = ft_strdup(mass[beg]);
		++i;
		++beg;
	}
	res[i] = NULL;
	return (res);
}

void	make_pipe(t_com *com)
{
	int		i;
	char	**mass;
	int		beg;

	i = 0;
	mass = com->args;
	beg = 0;
	while (mass[i])
	{
		if (mass[i][0] == '|')
		{
			com->args = submass(mass, beg, i);
			beg = i + 1;
			if (!(com->next = (t_com *)malloc(sizeof(t_com))))
				exit_error("Malloc error");
			com = com->next;
		}
		++i;
	}
	com->args = submass(mass, beg, i);
	com->next = NULL;
}

void	make_redirect(t_com *com)
{
	int		i;

	i = 0;
	while (com)
	{
		while (com->args[i])
		{
			
		}
	}
}

void	create_com(t_com *com)
{
	make_pipe(com);
	make_redirect(com);
}
