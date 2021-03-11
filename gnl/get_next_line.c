/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:47:18 by fignigno          #+#    #+#             */
/*   Updated: 2020/12/10 16:18:11 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_store(char **strs, int *count)
{
	size_t	i;
	size_t	size;
	char	*tmp;
	char	*res;

	i = 0;
	if (*strs == NULL)
		*strs = gnl_strjoin(NULL, "");
	size = gnl_strlen(*strs);
	*count = 0;
	while ((*strs)[i])
	{
		if ((*strs)[i] == '\n')
		{
			(*strs)[i] = '\0';
			*count = 1;
			break ;
		}
		++i;
	}
	res = gnl_strjoin(NULL, *strs);
	tmp = *strs;
	*strs = gnl_strjoin(NULL, *strs + i + ((i == size) ? 0 : 1));
	free(tmp);
	return (res);
}

int		find_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int		clean(char **line, int count)
{
	if (count > 0)
		return (1);
	if (*line != NULL)
		free(*line);
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*store = NULL;
	char			buf[BUFFER_SIZE + 1];
	char			*str;
	int				count;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1
		|| fd >= 1024)
		return (-1);
	str = check_store(&(store), &count);
	if (!count)
		while ((count = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[count] = '\0';
			str = gnl_strjoin(str, buf);
			if (find_line(str) >= 0)
			{
				free(store);
				store = str;
				*line = check_store(&(store), &count);
				return (1);
			}
		}
	*line = gnl_strjoin(NULL, str);
	free(str);
	return (clean(&(store), count));
}
