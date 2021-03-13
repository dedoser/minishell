/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:23:44 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 20:12:35 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	init_com(t_com **com, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!(com[i] = (t_com *)malloc(sizeof(t_com))))
			exit_error("Malloc error");
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

void	run_com(t_com **com, char *str, char **envp)
{
	int	count;
	int	i;

	count = count_coms(str);
	if (!(com = (t_com **)malloc(sizeof(t_com *) * (count_coms(str) + 1))))
		exit_error("Malloc error");
	init_com(com, count);
	parse_com(com, str);
	i = 0;
	while (com[i])
	{
		edit_envp(com[i], envp);
		++i;
	}
}

void	start(t_hist *hist)
{
	t_com	**com;
	char	*str;

	while (get_next_line(1, &str) > 0)
	{
		run_com(com, str, hist->envp);
		free(str);
	}
	free(str);
}
