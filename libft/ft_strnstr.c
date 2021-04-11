/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:51 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/09 23:42:34 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ret_value(char *heap, size_t i, size_t p, size_t len)
{
	if (i + p > len)
		return (NULL);
	return (&heap[i]);
}

char	*ft_strnstr(char *heap, const char *need, size_t len)
{
	size_t	i;
	size_t	p;
	size_t	need_len;

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
			return (ret_value(heap, i, p, len));
		++i;
	}
	return (NULL);
}
