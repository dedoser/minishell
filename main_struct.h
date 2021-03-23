/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:49:19 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/23 20:18:29 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H

typedef struct s_com
{
	char	*line;
	char	**args;
	int		out_fd;
	int		in_fd;
	struct s_com	*next;
}			t_com;

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

#endif
