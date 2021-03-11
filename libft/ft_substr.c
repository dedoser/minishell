/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:22:35 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/31 20:17:50 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		if ((res = (char *)malloc(sizeof(char))) == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	size = ft_strlen(s) - start;
	size = (size > len) ? len : size;
	if ((res = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}
