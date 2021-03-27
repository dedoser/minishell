/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_com.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:50 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/27 19:20:05 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	launch_com(t_com *com)
{
	while (com)
	{
		for (int i = 0; com->args[i]; ++i)
			printf("%s ", com->args[i]);
		printf("\n");
		printf("%d %d\n", com->in_fd, com->out_fd);
		com = com->next;
	}
}