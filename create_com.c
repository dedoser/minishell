/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:02:35 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/26 17:21:47 by fignigno         ###   ########.fr       */
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
	(*prev)->next = tmp->next->next;
	tmp->next->next = NULL;
	back_list(files, tmp);
	*cur = (*prev)->next;
	*prev = *cur;
}

void	next_pipe(t_com **com, t_arg **cur, t_arg **prev)
{
	(*prev)->next = NULL;
	if (!((*com)->next = (t_com *)malloc(sizeof(t_com))))
		exit_error("Malloc error");
	(*com) = (*com)->next;
	(*com)->list = (*cur)->next;
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

int		create_com(t_com *com)
{
	if (!check_pipes(com->list))
	{
		printf("Pipe error\n");
		return (0);
	}
	make_pipe(com);
	if (!check_files(com))
	{
		printf("Redirect error\n");
		return (0);
	}
	make_redirect(com);
	return (1);
}
