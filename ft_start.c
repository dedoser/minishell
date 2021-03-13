/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:23:44 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 15:24:16 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

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
		else if (str[i] == '\\')
			i += 2;
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

void	run_com(t_com **com, char *str)
{
	if (!(com = (t_com **)malloc(sizeof(t_com *) * (count_coms(str) + 1))))
		exit_error("Malloc error");
	// parse_com(com, str);
}

void	start(t_hist *hist)
{
	t_com	**com;
	char	*str;

	while (get_next_line(1, &str) > 0)
	{
		run_com(com, str);
		free(str);
	}
	free(str);
}
