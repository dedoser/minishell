/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:43:38 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:46:57 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

void	add_line(t_hist *hist, char *str)
{
	t_str	*list;

	list = hist->list;
	hist->last++;
	hist->cur = hist->last + 1;
	if (list->str == NULL)
		list->str = str;
	else
	{
		while (list->next)
			list = list->next;
		list->next = (t_str *)malloc(sizeof(t_str));
		alloc_check(list->next);
		list->next->str = str;
		list->next->next = NULL;
	}
}

void	delete_history(t_hist *hist)
{
	t_str	*list;

	while (hist->list)
	{
		list = hist->list;
		hist->list = hist->list->next;
		if (list->str)
			free(list->str);
		free(list);
	}
}

static t_str	*copy_list(t_str *list)
{
	t_str	*res;
	t_str	*tmp;

	res = (t_str *)malloc(sizeof(t_str));
	alloc_check(res);
	tmp = res;
	while (list)
	{
		tmp->str = ft_strdup(list->str);
		if (list->next)
		{
			tmp->next = (t_str *)malloc(sizeof(t_str));
			alloc_check(tmp->next);
			tmp = tmp->next;
		}
		list = list->next;
	}
	tmp->next = NULL;
	return (res);
}

t_hist	*history_copy(t_hist *hist)
{
	t_hist	*res;

	res = (t_hist *)malloc(sizeof(t_hist));
	alloc_check(res);
	res->envp = hist->envp;
	res->cur = hist->cur;
	res->last = hist->last;
	res->list = copy_list(hist->list);
	return (res);
}

void	delete_temp_history(t_hist *hist)
{
	t_str	*list;

	while (hist->list)
	{
		list = hist->list;
		hist->list = hist->list->next;
		if (list->str)
			free(list->str);
		free(list);
	}
	free(hist);
}
