/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:44:43 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/09 20:53:01 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long long n)
{
	int	res;

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

void	fill_str(char *str, long long dig, int size)
{
	while (dig != 0)
	{
		str[--size] = dig % 10 + '0';
		dig /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*res;
	int			size;
	long long	tmp;

	tmp = n;
	size = count(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
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
	fill_str(res, tmp, size);
	return (res);
}
