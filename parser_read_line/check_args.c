/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:13:56 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/26 16:42:00 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

int		check_files(t_com *com)
{
	t_arg	*list;

	while (com)
	{
		list = com->list;
		while (list)
		{
			if (list->line[0] == '>' ||
				list->line[0] == '<')
				if (list->next == NULL)
					return (0);
			list = list->next;
		}
		com = com->next;
	}
	return (1);
}

int		check_pipes(t_arg *list)
{
	if (list->line[0] == '|')
		return (0);
	while (list->next)
		list = list->next;
	if (list->line[0] == '|')
		return (0);
	return (1);
}
