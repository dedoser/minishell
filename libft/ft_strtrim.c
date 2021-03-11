/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:39:24 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/01 18:49:54 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				break ;
			++j;
		}
		if (s2[j] == '\0')
			break ;
		++i;
	}
	return (i);
}

static int	find_end(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	size;

	size = (int)ft_strlen(s1);
	i = 1;
	while (i <= size)
	{
		j = 0;
		while (s2[j])
		{
			if (s1[size - i] == s2[j])
				break ;
			++j;
		}
		if (s2[j] == '\0')
			break ;
		++i;
	}
	return (size - i);
}

char		*ft_strtrim(const char *s1, const char *s2)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	start = find_start(s1, s2);
	end = find_end(s1, s2);
	if (end == -1)
	{
		if ((res = (char *)malloc(1)) == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if ((res = (char *)malloc(end - start + 2)) == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		res[i++] = s1[start++];
	}
	res[i] = '\0';
	return (res);
}
