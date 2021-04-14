/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:09 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/14 20:29:54 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

char	**ft_split_envp(char *str, char c)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * 3);
	alloc_check(res);
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
	res = (t_envp *)malloc(sizeof(t_envp));
	alloc_check(envp);
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

void	shell_level(t_envp *envp)
{
	int		cur;
	t_envp	*prev;

	prev = envp;
	while (envp)
	{
		if (!ft_strcmp(envp->key, "SHLVL"))
		{
			cur = ft_atoi(envp->value);
			free(envp->value);
			envp->value = ft_itoa(cur + 1);
			return ;
		}
		prev = envp;
		envp = envp->next;
	}
	prev->next = (t_envp *)malloc(sizeof(t_envp));
	alloc_check(prev->next);
	prev = prev->next;
	prev->key = ft_strdup("SHLVL");
	prev->value = ft_strdup("1");
}

void	copy_envp(t_hist *hist, char **envp)
{
	int		i;
	char	*str;

	hist->envp = NULL;
	i = -1;
	while (envp[++i])
		ret_envp(&hist->envp, envp[i]);
	str = ft_strdup("?=0");
	ret_envp(&hist->envp, str);
	g_var.envp = hist->envp;
	shell_level(hist->envp);
	free(str);
}
