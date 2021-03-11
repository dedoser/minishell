/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:46:54 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/31 22:42:48 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;
	size_t	size;

	size = ft_strlen(s);
	tmp = NULL;
	i = 0;
	while (i < size)
	{
		if (s[i] == (char)c)
			tmp = &((char *)s)[i];
		++i;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	if (tmp == NULL)
		return (NULL);
	return ((char *)tmp);
}
