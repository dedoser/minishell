/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:01:22 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/09 23:34:34 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *src, char *dst)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char)
			* (ft_strlen(src) + ft_strlen(dst) + 1));
	if (res == NULL)
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

char	*ft_strfcat(char *src, char *dst)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char)
			* (ft_strlen(src) + ft_strlen(dst) + 1));
	if (res == NULL)
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
	return (res);
}
