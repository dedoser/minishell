/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:35:37 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:35:58 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/build_in.h"

int	echo_com(t_com *com)
{
	int		arg;
	int		i;

	arg = 0;
	i = 0;
	while (com->args[++i])
	{
		if (!ft_strcmp(com->args[i], "-n"))
			arg = 1;
		else
		{
			write(com->out_fd, com->args[i], ft_strlen(com->args[i]));
			if (com->args[i + 1])
				write(com->out_fd, " ", 1);
		}
	}
	if (!arg)
		write(com->out_fd, "\n", 1);
	return (0);
}
