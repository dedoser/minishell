/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:49:19 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/01 21:46:24 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <term.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/types.h>

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}					t_envp;

typedef struct s_arg
{
	char			*line;
	int				is_space;
	int				has_quote;
	struct s_arg	*next;
}					t_arg;

typedef struct	s_str
{
	char			*str;
	struct s_str	*next;
}				t_str;


typedef struct s_hist
{
	t_str	*list;
	int		cur;
	int		last;
	t_envp	*envp;
}			t_hist;

typedef struct s_com
{
	char	*line;
	char	**args;
	int		out_fd;
	int		in_fd;
	t_arg	*list;
	t_arg	*in_files;
	t_arg	*out_files;
	struct s_com	*next;
}			t_com;

typedef struct s_glob
{
	t_hist	*hist;
	pid_t	*child_pid;
	int		child_count;
	int		fd[2];
	int		prev_fd;
	int		next_fd;
	int		cur_child;
	t_envp	*envp;
}				t_glob;

#endif
