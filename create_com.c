/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:02:35 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/14 20:35:05 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	back_list(t_arg **list, t_arg *elem)
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

void	cut_files_from_list(t_arg **files, t_arg **cur, t_arg **prev)
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

void	next_pipe(t_com **com, t_arg **cur, t_arg **prev)
{
	if (*prev != *cur)
		(*prev)->next = NULL;
	(*com)->next = (t_com *)malloc(sizeof(t_com));
	alloc_check((*com)->next);
	(*com) = (*com)->next;
	(*com)->in_fd = 0;
	(*com)->out_fd = 1;
	(*com)->list = (*cur)->next;
	(*com)->in_files = NULL;
	(*com)->out_files = NULL;
	free((*cur)->line);
	free(*cur);
	*cur = (*com)->list;
	*prev = *cur;
}

void	make_pipe(t_com *com)
{
	t_arg	*cur;
	t_arg	*prev;

	cur = com->list;
	prev = com->list;
	while (cur)
	{
		if (cur->line[0] == '|')
			next_pipe(&com, &cur, &prev);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	com->next = NULL;
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

int	create_com(t_com *com)
{
	if (!com->list)
		return (0);
	if (!check_pipes(com->list))
	{
		write(2,
			"beautiful shell: syntax error near unexpected token `|\'\n", 56);
		return (0);
	}
	make_pipe(com);
	if (!check_files(com))
	{
		write(2,
			"beautiful shell: syntax error near unexpected token `newline\'\n",
			62);
		return (0);
	}
	pass_redirect(com);
	make_redirect(com);
	com->list = com->arg_list;
	return (1);
}
