/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_protecting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:09:46 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/17 22:46:07 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		len_without_slash(char *str, int isquote)
{
	int		i;
	int		len;
	char	prev;

	i = -1;
	len = 0;
	prev = str[0];
	while (str[++i])
	{
		if ((str[i] == '\\' || str[i] == '\"' || str[i] == '\'' ||
			str[i] == '$' || (!isquote)) && prev == '\\')
			continue ;
		len++;
		prev = str[i];
	}
	return (len - (isquote == 1));
}

char	*protect_dquote(char *str)
{
	char	*res;
	int		len;
	int		i;
	char	prev;

	++str;
	len = len_without_slash(str, 1);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		exit_error("Malloc error");
	i = 0;
	prev = str[0];
	while (i < len)
	{
		if (prev == '\\')
		res[i] = str[i];
	}
}

void	delete_protectong(t_arg *arg)
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
