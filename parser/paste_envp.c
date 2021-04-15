/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:43:36 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:32:28 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	end_of_envp(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\\' || str[i] == ' ' || str[i] == '$'
			|| str[i] == '\"')
			return (i);
	}
	return (i);
}

char	*find_envp(char *str, t_envp *envp, int *k, int *beg)
{
	int		i;
	int		end;

	++str;
	end = end_of_envp(str);
	while (envp)
	{
		i = -1;
		while (++i < end)
		{
			if (!(envp->key)[i] || !str[i] ||
				(envp->key)[i] != str[i])
				break ;
		}
		if (i == end)
			break ;
		envp = envp->next;
	}
	*k += end + 1;
	*beg = *k;
	if (!envp)
		return ("");
	return (envp->value);
}

int	does_contain_envp(char *str)
{
	int		i;
	char	prev;

	i = -1;
	prev = str[0];
	if (ft_strlen(str) == 1 && str[0] == '$')
		return (0);
	while (str[++i])
	{
		if (str[i] == '$' && prev != '\\')
			return (1);
		prev = str[i];
	}
	return (0);
}

char	*replace_all_envp(char *str, t_envp *envp)
{
	char	*res;
	int		beg;
	int		i;
	char	prev;

	i = 0;
	beg = 0;
	prev = str[0];
	res = NULL;
	while (prev && str[i])
	{
		if (str[i] == '$' && prev != '\\')
		{
			res = ft_strncat(res, &str[beg], i - beg);
			res = ft_strcat(res, find_envp(&str[i], envp, &i, &beg));
			continue ;
		}
		prev = str[i];
		++i;
	}
	if (beg != i)
		res = ft_strcat(res, &str[beg]);
	free(str);
	return (res);
}

void	paste_envp(t_arg *args, t_envp *envp)
{
	while (args)
	{
		if ((args->line)[0] != '\'' && does_contain_envp((args->line)))
			args->line = replace_all_envp(args->line, envp);
		args = args->next;
	}
}
