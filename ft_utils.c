/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:56:05 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 20:43:16 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	go_further(char *str, char c, int *i)
{
	while (str[(*i)++])
	{
		if (str[*i] == c)
		{
			(*i)++;
			return ;
		}
	}
}

char	*copy_further(char *dst, char *src, char c)
{
	char	*res;
	int		i;

	i = 0;
	++src;
	while (src[i] && src[i] != c)
		++i;
	src[i] = '\0';
	if (!(res = ft_strcat(dst, src)))
		exit_error("Malloc error");
	return (res);
}

// void	go_further_sl(char *str, char c, int *i)
// {
// 	while (str[*i])
// 	{
// 		if (str[*i] == c)
// 			return;
// 		if (str[*i] == '\\')
// 			(*i)++;
// 		(*i)++;
// 	}
// }

void	exit_error(const char *str)
{
	printf("%s\n", str);
	exit(0);
}
