/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:27:02 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/30 15:43:43 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*tmp;
	size_t			i;

	if ((res = (malloc(nmemb * size))) == NULL)
		return (NULL);
	i = 0;
	tmp = res;
	while (i < nmemb * size)
	{
		*tmp++ = 0;
		++i;
	}
	return (res);
}
