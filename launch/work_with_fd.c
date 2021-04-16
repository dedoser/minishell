/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:22:18 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:23:02 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

void	set_fd(t_com *com)
{
	if (g_var.cur_child == 1)
		g_var.prev_fd = 0;
	if (g_var.cur_child == g_var.child_count)
		g_var.next_fd = 1;
	dup2(g_var.prev_fd, 0);
	dup2(g_var.next_fd, 1);
	if (g_var.prev_fd != 0)
		close(g_var.prev_fd);
	if (g_var.next_fd != 1)
		close(g_var.next_fd);
	redirect_fd(com);
}

void	redirect_fd(t_com *com)
{
	if (com->in_fd != 0)
	{
		close(g_var.prev_fd);
		dup2(com->in_fd, 0);
	}
	if (com->out_fd != 1)
	{
		close(g_var.next_fd);
		dup2(com->out_fd, 1);
	}
}
