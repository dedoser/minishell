/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:37:09 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/03 18:15:00 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c, size_t *qw)
{
	size_t	i;
	size_t	j;
	int		res;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			s[i] = '\0';
		++i;
	}
	*qw = i;
	j = 0;
	res = 0;
	while (j + 1 < i)
	{
		if ((s[j] == '\0' && s[j + 1] != '\0') ||
			(j == 0 && s[j] != '\0'))
			++res;
		++j;
	}
	return (res);
}

static void	error_free(char **mass, char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(mass[i]);
		++i;
	}
	free(str);
	free(mass);
}

static char	*f(char **res, char *cop, size_t *cur_w, size_t j)
{
	if (j == 0 && cop[j] != '\0')
	{
		if ((res[*cur_w] = ft_strdup(&cop[j])) == NULL)
		{
			error_free(res, cop, *cur_w);
			return (NULL);
		}
		++(*cur_w);
		return (res[*cur_w - 1]);
	}
	if (cop[j] == '\0' && cop[j + 1] != '\0')
	{
		if ((res[*cur_w] = ft_strdup(&cop[j + 1])) == NULL)
		{
			error_free(res, cop, *cur_w);
			return (NULL);
		}
		++(*cur_w);
		return (res[*cur_w - 1]);
	}
	return (cop);
}

char		**ft_split(const char *s, char c)
{
	char	*cop;
	char	**res;
	size_t	i;
	size_t	j;
	size_t	cur_w;

	if (s == NULL)
		return (NULL);
	if (!(cop = ft_strdup(s)))
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (count(cop, c, &i) + 1))))
		return (NULL);
	j = 0;
	cur_w = 0;
	while (j + 1 < i)
	{
		if (!f(res, cop, &cur_w, j))
			return (NULL);
		++j;
	}
	res[cur_w] = NULL;
	free(cop);
	return (res);
}
