/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:24:17 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/14 20:32:42 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

int	redirect_line(char *str)
{
	int		i;

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
	res = (char *)malloc(sizeof(char) * (len + 1));
	alloc_check(res);
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

char	*pipe_found(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	alloc_check(res);
	res[0] = '|';
	res[1] = '\0';
	return (res);
}
