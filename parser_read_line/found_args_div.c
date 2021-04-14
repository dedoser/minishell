/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_args_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:27:21 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/14 20:28:27 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

int	end_quote(char quote, char prev, char cur)
{
	return (prev != '\\' || cur != quote);
}

int	quote_len(char *str, char quote)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i += 2;
		if (str[i] == quote)
			return (i + 2);
		++i;
	}
	return (i);
}

char	*quote_found(char **str, char quote)
{
	char	*res;
	int		i;
	int		len;

	(*str)++;
	len = quote_len(*str, quote);
	res = (char *)malloc(sizeof(char) * (len + 1));
	alloc_check(res);
	res[0] = quote;
	i = 0;
	while ((*str)[i] && i < len - 1)
	{
		res[i + 1] = (*str)[i];
		++i;
	}
	res[i + 1] = '\0';
	*str += i - 1;
	return (res);
}

int	end_spec(char cur, char prev)
{
	return ((cur == '|' || cur == '\'' || cur == '\"'
			|| cur == '<' || cur == '>' || cur == ' ') && prev != '\\');
}

int	len_spec(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (str[i] && !end_spec(str[i], c))
		++i;
	return (i);
}

char	*spec_found(char **str, char *prev)
{
	int		i;
	char	*res;
	char	c;

	i = 0;
	if (**str == '>' || **str == '<')
		return (redirect_found(str));
	if (**str == '|')
		return (pipe_found());
	res = (char *)malloc(sizeof(char) * (len_spec(*str) + 1));
	alloc_check(res);
	c = (*str)[i];
	while ((*str)[i] && !end_spec((*str)[i], c))
	{
		c = (*str)[i];
		res[i] = (*str)[i];
		++i;
	}
	res[i] = '\0';
	*prev = *(*str + i - 2);
	*str += i - 1;
	return (res);
}
