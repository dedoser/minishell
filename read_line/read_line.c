/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:55 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:21:48 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	init_save_term(struct termios *term)
{
	if (!isatty(0))
		exit_error("Terminal doesn't refer to any terminal");
	tcgetattr(0, &g_var.e_term);
	tcgetattr(0, term);
	g_var.e_term.c_lflag &= ~(ECHO);
	g_var.e_term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &g_var.e_term);
	tgetent(0, "xterm-256color");
}

char	*ret_str(char *str, t_hist *hist)
{
	int		i;
	char	*res;
	t_str	*list;

	if (hist->cur == hist->last + 1)
		return (str);
	i = 0;
	list = hist->list;
	while (++i < hist->cur)
		list = list->next;
	if (hist->mod)
		res = ft_strcat(ft_strdup(list->str), str);
	else
		res = ft_strdup(list->str);
	free(str);
	return (res);
}

char	*read_line(t_hist *hist)
{
	char			buf[200];
	int				l;

	buf[0] = '\0';
	g_var.str = ft_strdup("");
	tputs(save_cursor, 1, ft_putchar);
	while (ft_strncmp(buf, "\n", 1))
	{
		l = read(0, buf, 100);
		buf[l] = '\0';
		if (!press_key(buf, g_var.str, hist))
		{
			write(1, buf, l);
			if (buf[l - 1] != '\n' && !(buf[l - 1] == '\4'
					&& ft_strlen(g_var.str)))
			{
				g_var.str = ft_strcat(g_var.str, buf);
				hist->mod = 1;
			}
		}
		if (!ft_strcmp(buf, "\4") && ft_strlen(g_var.str) == 1)
			break ;
	}
	return (ret_str(g_var.str, hist));
}
