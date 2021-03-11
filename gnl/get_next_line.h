/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walker <walker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:48:18 by fignigno          #+#    #+#             */
/*   Updated: 2020/12/10 17:18:43 by walker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

int					get_next_line(const int fd, char **line);
char				*check_store(char **strs, int *count);
char				*gnl_strjoin(char *s1, const char *s2);
size_t				gnl_strlen(const char *s);
#endif
