/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:09 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/11 22:22:19 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

static int	envp_count(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
		++i;
	return (i);
}

void	copy_envp(t_hist *hist, char **envp)
{
	int		count;
	int		i;

	count = envp_count(envp);
	if (!(hist->envp = (char **)malloc(sizeof(char *) * (count + 1))))
		exit_error("Malloc error");
	i = 0;
	while (envp[i])
	{
		hist->envp[i] = ft_strdup(envp[i]);
		++i;
	}
}
