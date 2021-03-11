/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:04:12 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/31 23:32:19 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			++i;
		}
	}
	else
		while (n)
		{
			--n;
			cdest[n] = csrc[n];
		}
	return (dest);
}
