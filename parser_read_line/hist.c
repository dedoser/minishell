/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:09 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/01 21:47:37 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

char	**ft_split_envp(char *str, char c)
{
	char	**res;
	int		i;

	if (!(res = (char **)malloc(sizeof(char *) * 3)))
		exit_error("Malloc error");
	i = -1;
	while (str[++i])
		if (str[i] == c)
			break ;
	str[i] = '\0';
	res[0] = ft_strdup(str);
	res[1] = ft_strdup(&str[i + 1]);
	res[2] = NULL;
	return (res);
}

void	ret_envp(t_envp **envp, char *str)
{
	char	**mass;
	t_envp	*res;
	t_envp	*tmp;

	mass = ft_split_envp(str, '=');
	if (!(res = (t_envp *)malloc(sizeof(t_envp))))
		exit_error("Malloc error");
	res->key = mass[0];
	res->value = mass[1];
	res->next = NULL;
	free(mass);
	if (*envp == NULL)
		*envp = res;
	else
	{
		tmp = *envp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = res;
	}
}

void	copy_envp(t_hist *hist, char **envp)
{
	int	i;

	hist->envp = NULL;
	i = -1;
	while (envp[++i])
		ret_envp(&hist->envp, envp[i]);
}
