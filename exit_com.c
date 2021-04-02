/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:24:52 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/02 20:23:56 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	exit_com(t_com *com, t_envp *envp)
{
	free(com);
	free(envp);
	tcsetattr(0, TCSANOW, &g_var.term);
	exit(0);
}
