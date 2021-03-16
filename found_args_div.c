/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_args_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:27:21 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 23:39:50 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		len_arg(char *str, char div)
{
	int	i;

	i = 0;
	while (str[i])
	{
		
		if (str[i] == div)
			return (i);
		++i;
	}
	return (i);
}

char	*quote_found(char **beg, char **str, char quote)
{
	char	*res;
	int		i;

	(*str)++;
	if (!(res = (char *)malloc(sizeof(char) * (len_arg(*str, quote) + 1))))
		exit_error("Malloc_error");
	while (*str[i] && *str[i] != quote)
	{
		res[i] = *str[i];
		++i;
	}
	res[i] = '\0';
	skip_spaces(str);
	*beg = *str;
	return (res);
}

