/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:10:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/17 20:57:50 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		is_special_char(char c)
{
	if (c != '\'' && c != '\"' && c != ' ')
		return (1);
	return (0);
}

t_arg	*cut_to_args(char *str)
{
	t_arg	*res;
	char	*tmp;
	char	*beg;
	int		is_space;

	res = NULL;
	is_space = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			add_str(&res, quote_found(&str, *str), is_space);
		else if (is_special_char(*str))
			add_str(&res, spec_found(&str), is_space);
		is_space = *str == ' ';
		++str;
	}
	return (res);
}

void	main_parcing(t_com *com, t_envp *envp)
{
	t_arg	*res;

	res = cut_to_args(com->line);
	paste_envp(res, envp);
}
