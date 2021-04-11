/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:38:33 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/09 20:40:03 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int n)
{
	int	res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		++res;
	}
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		write(fd, "-", 1);
	}
	if (tmp == 0)
	{
		c = '0';
		write(fd, &c, 1);
		return ;
	}
	if (tmp / 10 == 0)
	{
		c = tmp + '0';
		write(fd, &c, 1);
		return ;
	}
	ft_putnbr_fd(tmp / 10, fd);
	c = tmp % 10 + '0';
	write(fd, &c, 1);
}
