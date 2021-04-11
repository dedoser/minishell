/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:35:23 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/10 02:45:42 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dig_sign(int sign, char dig)
{
	if (sign)
		return ('0' - dig);
	else
		return (dig - '0');
}

int	ft_atoi(const char *s)
{
	int			sign;
	long long	res;
	int			i;

	i = 0;
	sign = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == '\n')
		++i;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = (s[i] == '-') * (-1);
		++i;
	}
	res = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			break ;
		res = res * 10 + dig_sign(sign, s[i]);
		++i;
	}
	if (res < -2147483648 || res > 2147483647)
		return (-1);
	return (res);
}
