/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:56:05 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:32:21 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	go_further(char *str, char c, int *i)
{
	while (str[(*i)++])
	{
		if (str[*i] == c)
		{
			(*i)++;
			return ;
		}
	}
}

void	add_str(t_arg **lst, char *str, int is_space)
{
	t_arg	*tmp;
	t_arg	*new_elem;

	tmp = *lst;
	new_elem = (t_arg *)malloc(sizeof(t_arg));
	alloc_check(new_elem);
	new_elem->line = str;
	new_elem->has_quote = (str[0] == '\'' || str[0] == '\"');
	new_elem->is_space = is_space;
	new_elem->next = NULL;
	if (tmp == NULL)
	{
		*lst = new_elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
}

void	exit_error(const char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	alloc_check(void *ptr)
{
	if (!ptr)
		exit_error("Malloc error");
}
