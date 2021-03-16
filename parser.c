/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:10:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 23:40:13 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

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
		else if (str[i] == '\\')
			i += 2;
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
}

char	**cut_to_args(char *str)
{
	char	**res;
	char	*tmp;
	char	*beg;

	res = NULL;
	beg = str;
	while (*str)
	{
		if (*str == '\\')
			++str;
		else if (*str == '\'')
			res = add_str(res, quote_found(&beg, &str, '\''));
		else if (*str == '\"')
			res = add_str(res, quote_found(&beg, &str, '\"'));
		else if (*str == ' ')
			res = add_str(res, space_found(&beg, &str));
		else
			++str;
	}
	return (res);
}

void	main_parcing(t_com *com, char **envp)
{
	
}
