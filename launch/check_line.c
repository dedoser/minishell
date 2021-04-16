/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:20:15 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:20:35 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

int	check_line(char *str)
{
	char	prev;
	int		i;

	prev = str[0];
	if (prev == ';')
		return (0);
	i = 1;
	while (str[i])
	{
		if (prev == str[i] && prev == ';')
			return (0);
		prev = str[i];
		++i;
	}
	return (1);
}
