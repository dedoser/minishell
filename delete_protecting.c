/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_protecting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:09:46 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/18 23:49:58 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		len_without_protect(char *str, int isquote)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (!((isquote && (str[i + 1] == '\\' || str[i + 1] == '\"' ||
				str[i + 1] == '$')) || !isquote))
				len++;
			i++;
		}
		i++;
		len++;
	}
	return (len);
}

char	*protect_dquote(char *str)
{
	char	*res;
	int		i;
	int		len;

	len = len_without_protect(str, 1);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		exit_error("Malloc error");
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (!(str[i + 1] == '\\' || str[i + 1] == '\"' ||
				str[i + 1] == '$'))
			{
				res[len++] = str[i];
			}
			i++;
		}
		res[len++] = str[i++];
	}
	res[len] = '\0';
	free(str);
	return (res);
}

char	*protect_simple(char *str)
{
	char	*res;
	int		i;
	int		len;

	len = len_without_protect(str, 0);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		exit_error("Malloc error");
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		res[len++] = str[i++];
	}
	res[len] = '\0';
	free(str);
	return (res);
}

void	delete_protecting(t_arg *arg)
{
	while (arg)
	{
		if ((arg->line)[0] == '\"')
			arg->line = protect_dquote(arg->line);
		else if ((arg->line)[0] != '\'')
			arg->line = protect_simple(arg->line);
		arg = arg->next;
	}
}
