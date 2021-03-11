/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:44:43 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/31 20:39:36 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long long n)
{
	int res;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char		*res;
	int			size;
	long long	tmp;

	tmp = n;
	size = count(n);
	if ((res = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	res[size] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		tmp *= -1;
	}
	if (tmp == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (tmp != 0)
	{
		res[--size] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (res);
}
