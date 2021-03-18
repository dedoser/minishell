/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:01:22 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/18 16:42:45 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *src, char *dst)
{
	int		i;
	int		j;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) *
		(ft_strlen(src) + ft_strlen(dst) + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (src && src[i])
	{
		res[i] = src[i];
		++i;
	}
	while (dst[++j])
		res[i + j] = dst[j];
	res[i + j] = '\0';
	if (src)
		free(src);
	return (res);
}
