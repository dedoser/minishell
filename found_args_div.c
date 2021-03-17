/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_args_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:27:21 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/17 22:35:31 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		end_quote(char quote, char prev, char cur)
{
	return (prev != '\\' || cur != quote);
}

int		quote_len(char *str, char quote)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (str[i])
	{
		if (str[i] == quote && end_quote(quote, c, str[i]))
			return (i + 2);
		c = str[i];
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
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		exit_error("Malloc_error");
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

// char	*d_quote_found(char **str)
// {
// 	char	*res;
// 	int		i;
// 	int		j;

// 	(*str)++;
// 	if (!(res = (char *)malloc(sizeof(char) * (d_quote_len(*str)))))
// 		exit_error("Malloc error");
// 	res[0] = '\"';
// 	i = 0;
// 	j = 1;
// 	while (*str[i] && *str[i] != '\"')
// 	{
// 		if (*str[i] == '\'' && (*str[i + 1] == '\\' || *str[i + 1] == '\"' ||
// 			*str[i + 1] == '$'))
// 			++i;
// 		res[j] = *str[i];
// 		++j;
// 		++i;
// 	}
// 	res[j] = '\"';
// 	res[j + 1] = '\0';
// 	return (res);
// }

int		end_spec(char cur, char prev)
{
	return ((cur == '|' || cur == '\'' || cur == '\"' ||
			cur == '<' || cur == '>' || cur == ' ') && prev != '\\');
}

int		len_spec(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[i];
	while (str[i] && !end_spec(str[i], c))
		++i;
	return (i);
}

char	*spec_found(char **str)
{
	int		i;
	char	*res;
	char	c;

	i = 0;
	if (**str == '>' || **str == '<')
		return (redirect_found(str));
	if (**str == '|')
		return (pipe_found(str));
	if (!(res = (char *)malloc(sizeof(char) * (len_spec(*str) + 1))))
		exit_error("Malloc error");
	c = (*str)[i];
	while ((*str)[i] && !end_spec((*str)[i], c))
	{
		c = (*str)[i];
		res[i] = (*str)[i];
		++i;
	}
	res[i] = '\0';
	*str += i - 1;
	return (res);
}
