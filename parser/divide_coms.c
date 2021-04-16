/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_coms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:42:38 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:10:46 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	init_com(t_com **com, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		com[i] = (t_com *)malloc(sizeof(t_com));
		alloc_check(com[i]);
		com[i]->in_fd = 0;
		com[i]->out_fd = 1;
		com[i]->in_files = NULL;
		com[i]->out_files = NULL;
		com[i]->args = NULL;
		++i;
	}
	com[i] = NULL;
}

static int	count_coms(char *str)
{
	int		i;
	int		res;
	int		ind;

	i = 0;
	res = 0;
	ind = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			go_further(str, '\'', &i);
		else if (str[i] == '\"')
			go_further(str, '\"', &i);
		else if (str[i] == ';')
		{
			res++;
			++i;
			ind = 1;
		}
		else
			++i;
	}
	return (res + 1);
}

static void	divide_coms(t_com **com, char *str, int count)
{
	int	i;
	int	cur;
	int	prev;

	i = 0;
	cur = 0;
	prev = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			go_further(str, str[i], &i);
		else if (str[i] == ';')
		{
			str[i] = '\0';
			com[cur++]->line = ft_strdup(&str[prev]);
			prev = i + 1;
			++i;
		}
		else
			++i;
	}
	if (cur < count)
		com[cur++]->line = ft_strdup(&str[prev]);
	com[cur] = NULL;
	free(str);
}

t_com	**parse_com(char *str, t_envp *envp)
{
	int		count;
	int		i;
	t_com	**com;

	count = count_coms(str);
	com = (t_com **)malloc(sizeof(t_com *) * (count_coms(str) + 1));
	alloc_check(com);
	init_com(com, count);
	divide_coms(com, ft_strdup(str), count);
	i = 0;
	while (com[i])
	{
		main_parcing(com[i], envp);
		++i;
	}
	g_var.com = com;
	return (com);
}
