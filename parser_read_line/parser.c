/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:10:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/23 20:20:17 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

int		is_special_char(char c)
{
	if (c != '\'' && c != '\"' && c != ' ')
		return (1);
	return (0);
}

t_arg	*cut_to_args(char *str)
{
	t_arg	*res;
	int		is_space;
	char	prev;

	res = NULL;
	is_space = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			add_str(&res, quote_found(&str, *str), is_space);
		else if (is_special_char(*str))
			add_str(&res, spec_found(&str, &prev), is_space);
		is_space = (*str == ' ' && prev != '\\');
		++str;
	}
	return (res);
}

void	main_parcing(t_com *com, t_envp *envp)
{
	t_arg	*res;

	res = cut_to_args(com->line);
	paste_envp(res, envp);
	change_spaces(res);
	delete_protecting(res);
	// while (res)
	// {
	// 	printf("%s %d\n", res->line, res->is_space);
	// 	res = res->next;
	// }
	com->args = create_final_mass(res);
	// for (int i = 0; com->args[i]; ++i)
	// 	printf("%s\n", com->args[i]);
}
