/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:24:17 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/17 17:34:41 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		redirect_line(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] && (str[i] == '>' || str[i] == '<'))
		++i;
	return (i);
}

char	*redirect_found(char **str)
{
	char	*res;
	int		len;
	int		i;

	len = redirect_line(*str);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		exit_error("Malloc error");
	i = 0;
	while (i < len)
	{
		res[i] = (*str)[i];
		++i;
	}
	res[i] = '\0';
	*str += i - 1;
	return (res);
}

char	*pipe_found(char **str)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 2)))
		exit_error("Malloc error");
	res[0] = '|';
	res[1] = '\0';
	return (res);
}
