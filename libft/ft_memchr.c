/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:59:15 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/01 18:49:09 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	size_t			len;

	ptr_s = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		if (*ptr_s == (unsigned char)c)
			return (ptr_s);
		++ptr_s;
		++len;
	}
	return (NULL);
}
