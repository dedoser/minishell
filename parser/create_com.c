/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:02:35 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:25:15 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	next_pipe(t_com **com, t_arg **cur, t_arg **prev)
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
	(*com)->args = NULL;
	free((*cur)->line);
	free(*cur);
	*cur = (*com)->list;
	*prev = *cur;
}

static void	make_pipe(t_com *com)
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
