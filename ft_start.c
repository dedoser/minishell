/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:23:44 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/16 21:18:30 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	start(t_hist *hist)
{
	t_com	**com;
	char	*str;

	while (get_next_line(0, &str) > 0)
	{
		parse_com(com, str, hist->envp);
		free(str);
	}
	free(str);
}
