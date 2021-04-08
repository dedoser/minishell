/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:49:29 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/08 16:49:03 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	tmp;
	int		i;
	char	*res;
	int		dst_len;

	tmp = ft_strlen(src);
	dst_len = ft_strlen(dst);
	tmp = tmp > n ? n : tmp;
	if (!(res = (char *)malloc(sizeof(char) * (tmp + 1 + dst_len))))
		return (NULL);
	i = -1;
	if (dst)
		while (dst[++i])
			res[i] = dst[i];
	i = -1;
	while (++i < (int)tmp)
		res[i + dst_len] = src[i];
	res[i + dst_len] = '\0'; 
	if (dst)
		free(dst);
	return (res);
}
