/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_final_mass.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:02:52 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/11 18:51:49 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

void	change_spaces(t_arg *arg)
{
	char	c;
	int		prev_arg;

	prev_arg = 0;
	while (arg)
	{
		c = arg->line[0];
		if (prev_arg)
			arg->is_space = 1;
		if ((c == '|' || c == '>' || c == '<') && !arg->is_space)
		{
			arg->is_space = 1;
			prev_arg = 1;
		}
		else
			prev_arg = 0;
		arg = arg->next;
	}
}

char	*delete_quotes(char *str)
{
	char	*res;
	int		i;
	int		len;

	len = ft_strlen(str) - 2;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		exit_error("Malloc error");
	i = 1;
	while (str[i + 1])
	{
		res[i - 1] = str[i];
		++i;
	}
	res[i - 1] = '\0';
	free(str);
	return (res);
}

char	**push_bask(char **mass, char *str)
{
	char	**res;
	int		i;

	i = 0;
	if (mass)
		while (mass[i])
			i++;
	if (!(res = (char **)malloc(sizeof(char *) * (i + 2))))
		exit_error("Malloc error");
	i = -1;
	if (mass)
	{
		while (mass[++i])
		{
			res[i] = mass[i];
		}
	}
	else
		++i;
	res[i] = str;
	res[i + 1] = NULL;
	if (mass)
		free(mass);
	return (res);
}

void	free_arg(t_arg *arg)
{
	t_arg	*prev;

	while (arg)
	{
		prev = arg;
		free(arg->line);
		arg = arg->next;
		free(prev);
	}
}

char	**create_final_mass(t_arg *arg)
{
	char	**res;
	char	*str;

	str = NULL;
	res = NULL;
	while (arg)
	{
		if (arg->has_quote)
			arg->line = delete_quotes(arg->line);
		str = ft_strcat(str, arg->line);
		arg = arg->next;
		if (!arg || arg->is_space)
		{
			res = push_bask(res, str);
			str = NULL;
		}
	}
	free_arg(arg);
	return (res);
}
