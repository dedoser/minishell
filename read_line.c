/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:55 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/19 23:36:32 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int main()
{
	struct termios t;
	struct termios tmp;
	char			str[2000];
	char			*t_name = "xterm-256color";
	int				l;

	tcgetattr(0, &t);
	tcgetattr(0, &tmp);
	t.c_lflag &= ~(ECHO);
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);
	tgetent(0, t_name);
	while (ft_strncmp(str, "\4", 1))
	{
		tputs(save_cursor, 1, ft_putchar);
		while (1)
		{
			l = read(0, str, 100);
			if (!ft_strncmp(str, "\e[A", ft_strlen("\e[A")))
			{
				tputs(restore_cursor, 1, &ft_putchar);
				tputs(tigetstr("ed"), 1, &ft_putchar);
				write(1, "previous", 8);
			}
			else if (!ft_strncmp(str, "\e[B", ft_strlen("\e[B")))
			{
				tputs(restore_cursor, 1, &ft_putchar);
				tputs(tigetstr("ed"), 1, &ft_putchar);
				write(1, "next", 4);
			}
			else if (!ft_strncmp(str, "\177", 1))
			{
				tputs(cursor_left, 1, &ft_putchar);
				tputs(tigetstr("ed"), 1, &ft_putchar);
			}
			else
				write(1, str, l);
			if (!ft_strncmp(str, "\n", 1) || !ft_strncmp(str, "\4", 1))
				break ;
		}
	}
	printf("%d", l);
	write(1, "\n", 1);
	tcsetattr(0, TCSANOW, &tmp);
	return (0);
}
