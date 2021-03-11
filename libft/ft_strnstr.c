/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:51 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/30 14:06:39 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *heap, const char *need, size_t len)
{
	size_t i;
	size_t p;
	size_t need_len;

	i = 0;
	need_len = ft_strlen(need);
	if (!need_len)
		return (heap);
	while (i < len && heap[i])
	{
		p = 0;
		while (need[p])
		{
			if (need[p] != heap[i + p])
				break ;
			++p;
		}
		if (p == need_len)
		{
			return (i + p > len ? NULL : &heap[i]);
		}
		++i;
	}
	return (NULL);
}
