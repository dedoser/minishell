/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:23:44 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/26 18:34:18 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	add_line(t_hist *hist, char *str)
{
	t_str	*list;

	list = hist->list;
	hist->last++;
	hist->cur = hist->last;
	if (list->str == NULL)
	{
		list->str = str;
	}
	else
	{
		while (list->next)
			list = list->next;
		if (!(list->next = (t_str *)malloc(sizeof(t_str))))
			exit_error("Malloc error");
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

t_hist	*history_copy(t_hist *hist)
{
	t_hist	*res;
	t_str	*list;
	t_str	*tmp;

	if (!(res = (t_hist *)malloc(sizeof(t_hist))))
		exit_error("Malloc error");
	res->envp = hist->envp;
	res->cur = hist->cur;
	res->last = hist->last;
	list = hist->list;
	if (!(tmp = (t_str *)malloc(sizeof(t_str))))
		exit_error("Malloc error");
	res->list = tmp;
	while (list)
	{
		tmp->str = ft_strdup(list->str);
		if (!(tmp->next = (t_str *)malloc(sizeof(t_str))))
			exit_error("Malloc error");
		tmp = tmp->next;
		list = list->next;
	}
	tmp->next = NULL;
	return (res);
}

void	delete_temp_history(t_hist *hist)
{
	t_str	*tmp;

	tmp = hist->list;
	while (tmp)
	{
		tmp = tmp->next;
		free(hist->list->str);
		free(hist->list);
	}
	free(hist);
}

void	start(t_hist *hist)
{
	t_com	**com;
	char	*str;
	t_hist	*copy_hist;

	while (1)
	{
		copy_hist = history_copy(hist);
		str = read_line(copy_hist);
		if (!ft_strncmp(str, "\4", 1))
			break ;
		if (ft_strlen(str))
		{
			add_line(hist, str);
			parse_com(com, str, hist->envp);
			// run_com(com);
		}
	}
	delete_history(hist);
}
