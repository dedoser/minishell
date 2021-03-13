/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:10:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 20:48:53 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	parse_com(t_com **com, char *str)
{
	int	i;
	int	cur;
	int	prev;

	i = 0;
	cur = 0;
	prev = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			go_further(str, str[i], &i);
		else if (str[i] == '\\')
			i += 2;
		else if (str[i] == ';')
		{
			str[i] = '\0';
			com[cur]->line = ft_strdup(&str[prev]);
			prev = i + 1;
			cur++;
			++i;
		}
		else
			++i;
	}
	com[cur]->line = ft_strdup(&str[prev]);
}

char	*replace_envp(char *dst, char *src, char **envp)
{
	char	*res;
	int		i;

	i = 0;
	while (src[i] && src[i] != '\"')
	{
		if (src[i] == '\\' && src[i + 1] && src[i + 1] != '\\' && src[i + 1] != '$' && src[i + 1] != '\"')
			i += 2;
	}
}

void	edit_envp(char *str, t_com *com, char **envp)
{
	char	*tmp;

	tmp = NULL;
	while (*str)
	{
		if (*str == '\'')
			tmp = copy_further(tmp, str, '\'');
		else if (*str == '\"')
			tmp = replace_envp(tmp, str, envp)
	}
}
