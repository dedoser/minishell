/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:04:12 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/09 23:23:22 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	go_up(unsigned char *src, unsigned char *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		++i;
	}
}

void	go_back(unsigned char *src, unsigned char *dest, size_t n)
{
	while (n)
	{
		--n;
		dest[n] = src[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	if ((dest == NULL && src == NULL))
		return (dest);
	i = 0;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	if (cdest < csrc)
		go_up(csrc, cdest, n);
	else
		go_back(csrc, cdest, n);
	return (dest);
}
