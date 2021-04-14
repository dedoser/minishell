/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:23:44 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/14 19:52:45 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

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

t_str	*copy_list(t_str *list)
{
	t_str	*res;
	t_str	*tmp;

	if (!(res = (t_str *)malloc(sizeof(t_str))))
		exit_error("Malloc error");
	tmp = res;
	while (list)
	{
		tmp->str = ft_strdup(list->str);
		if (list->next)
		{
			if (!(tmp->next = (t_str *)malloc(sizeof(t_str))))
				exit_error("Malloc error");
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

	if (!(res = (t_hist *)malloc(sizeof(t_hist))))
		exit_error("Malloc error");
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

int		check_line(char *str)
{
	char	prev;
	int		i;

	prev = str[0];
	if (prev == ';')
		return (0);
	i = 1;
	while (str[i])
	{
		if (prev == str[i] && prev == ';')
			return (0);
		prev = str[i];
		++i;
	}
	return (1);
}

void	start(t_hist *hist)
{
	t_com	**com;
	char	*str;

	com = NULL;
	while (1)
	{
		signal(SIGINT, sigint_react);
		write(1, "beautiful shell$ ", 17);
		g_var.hist = history_copy(hist);
		str = read_line(g_var.hist);
		delete_temp_history(g_var.hist);
		if (str && !ft_strncmp(str, "\4", 1))
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (ft_strlen(str))
		{
			add_line(hist, str);
			if (!check_line(str))
			{
				write(2,
				"beautiful shell$: syntax error near unexpected token `;\'\n",
				57);
				continue ;
			}
			com = parse_com(str, hist->envp);
			g_var.com = com;
			run_com(com, hist->envp);
			delete_com(com);
		}
	}
	delete_history(hist);
}
