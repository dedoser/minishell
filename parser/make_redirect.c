/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:23:47 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:25:33 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	back_list(t_arg **list, t_arg *elem)
{
	t_arg	*tmp;

	if (*list == NULL)
		*list = elem;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

static void	cut_files_from_list(t_arg **files, t_arg **cur, t_arg **prev)
{
	t_arg	*tmp;

	tmp = *cur;
	if (*prev != tmp)
		(*prev)->next = tmp->next->next;
	tmp->next->next = NULL;
	back_list(files, tmp);
	if (*cur == *prev)
		*cur = (*cur)->next->next;
	else
	{
		*cur = (*prev)->next;
		*prev = *cur;
	}
}

void	make_redirect(t_com *com)
{
	t_arg	*cur;
	t_arg	*prev;

	while (com)
	{
		cur = com->list;
		prev = cur;
		while (cur)
		{
			if (cur->line[0] == '>')
				cut_files_from_list(&(com->out_files), &cur, &prev);
			else if (cur->line[0] == '<')
				cut_files_from_list(&(com->in_files), &cur, &prev);
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		com = com->next;
	}
}

void	pass_redirect(t_com *com)
{
	while (com->arg_list)
	{
		if (com->arg_list->line[0] == '>' || com->arg_list->line[0] == '<')
			com->arg_list = com->arg_list->next->next;
		else
			break ;
	}
}
