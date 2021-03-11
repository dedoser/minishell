/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:56:12 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/29 19:24:26 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *d, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_src;
	size_t			len;

	ptr_d = (unsigned char *)d;
	ptr_src = (unsigned char *)src;
	len = 0;
	while (len < n && *ptr_d == *ptr_src)
	{
		++ptr_d;
		++ptr_src;
		++len;
	}
	if (len == n)
		return (0);
	return (*ptr_d - *ptr_src);
}
