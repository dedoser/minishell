/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_coms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:42:38 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/24 20:10:34 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

void	init_com(t_com **com, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!(com[i] = (t_com *)malloc(sizeof(t_com))))
			exit_error("Malloc error");
		com[i]->in_fd = 0;
		com[i]->out_fd = 1;
		com[i]->in_files = NULL;
		com[i]->out_files = NULL;
		++i;
	}
	com[i] = NULL;
}

int		count_coms(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
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
		}
		else
			++i;
	}
	return (res);
}

void	divide_coms(t_com **com, char *str)
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
			com[cur]->line = ft_strdup(&str[prev]);
			prev = i + 1;
			cur++;
			++i;
		}
		else
			++i;
	}
	com[cur]->line = ft_strdup(&str[prev]);
	free(str);
}

void	parse_com(t_com **com, char *str, t_envp *envp)
{
	int	count;
	int	i;

	count = count_coms(str);
	if (!(com = (t_com **)malloc(sizeof(t_com *) * (count_coms(str) + 1))))
		exit_error("Malloc error");
	init_com(com, count);
	divide_coms(com, ft_strdup(str));
	i = 0;
	while (com[i])
	{
		main_parcing(com[i], envp);
		++i;
	}
}
