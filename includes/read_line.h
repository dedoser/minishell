/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:21:25 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 19:15:32 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINE_H
# define READ_LINE_H

# include "main_struct.h"
# include "exit_error.h"
# include "deletes.h"

int		ft_putchar(int c);
void	print_prev(t_hist *hist);
void	print_next(t_hist *hist, char *str);
void	move_cursor(char *line);
void	press_backspace(char *str, t_hist *hist);
int		press_key(char *buf, char *str, t_hist *hist);
void	init_save_term(struct termios *term);
char	*read_line(t_hist *hist);

#endif
