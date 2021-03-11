/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:51:01 by fignigno          #+#    #+#             */
/*   Updated: 2020/12/10 17:18:17 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		++s;
		++i;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if ((res = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			++i;
		}
		free(s1);
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		++j;
	}
	res[i + j] = '\0';
	return (res);
}
