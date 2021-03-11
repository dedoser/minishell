/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:56:05 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/12 00:01:49 by fignigno         ###   ########.fr       */
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
			return;
		}
	}
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
