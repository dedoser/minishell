/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:24:52 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/03 17:07:28 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	change_errno(t_envp *envp, int err)
{
	while (envp)
	{
		if (!ft_strcmp(envp->key, "?"))
			break ;
		envp = envp->next;
	}
	free(envp->value);
	envp->value = ft_itoa(err);
}

void	exit_com(void)
{
	delete_com(g_var.com);
	tcsetattr(0, TCSANOW, &g_var.term);
	exit(0);
}
