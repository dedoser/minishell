/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:55 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/01 20:39:37 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../funcs.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

// int main()
// {

// 	char			str[2000];
// 	int				l;

// 	while (ft_strncmp(str, "\4", 1))
// 	{
// 		tputs(save_cursor, 1, ft_putchar);
// 		while (1)
// 		{
// 			l = read(0, str, 100);
// 			if (!ft_strncmp(str, "\e[A", ft_strlen("\e[A")))
// 			{
// 				tputs(restore_cursor, 1, &ft_putchar);
// 				tputs(clr_eos, 1, &ft_putchar);
// 				write(1, "previous", 8);
// 			}
// 			else if (!ft_strncmp(str, "\e[B", ft_strlen("\e[B")))
// 			{
// 				tputs(restore_cursor, 1, &ft_putchar);
// 				tputs(clr_eos, 1, &ft_putchar);
// 				write(1, "next", 4);
// 			}
// 			else if (!ft_strncmp(str, "\177", 1))
// 			{
// 				tputs(cursor_left, 1, &ft_putchar);
// 				tputs(delete_character, 1, &ft_putchar);
// 			}
// 			else
// 				write(1, str, l);
// 			if (!ft_strncmp(str, "\n", 1) || !ft_strncmp(str, "\4", 1))
// 				break ;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	tcsetattr(0, TCSANOW, &tmp);
// 	return (0);
// }

void	init_save_term(struct termios *term)
{
	struct termios	t;

	if (!isatty(0))
		exit_error("Terminal doesn't refer to any terminal");
	tcgetattr(0, &t);
	tcgetattr(0, term);
	t.c_lflag &= ~(ECHO);
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);
	tgetent(0, "xterm-256color");
}

void	print_prev(t_hist *hist)
{
	t_str	*list;
	int		i;
	char	*output;

	hist->cur--;
	if (hist->cur <= 0)
	{
		hist->cur++;
		return ;
	}
	list = hist->list;
	i = 0;
	while (++i < hist->cur)
		list = list->next;
	output = list->str;
	tputs(restore_cursor, 1, &ft_putchar);
	tputs(clr_eos, 1, &ft_putchar);
	write(1, output, ft_strlen(output));
}

void	print_next(t_hist *hist, char *str)
{
	t_str	*list;
	int		i;
	char	*output;

	if (hist->cur == hist->last + 1)
		return ;
	hist->cur++;
	if (hist->cur == hist->last + 1)
	{
		output = str;
		hist->cur = hist->last + 1;
	}
	else
	{
		list = hist->list;
		i = 0;
		while (++i < hist->cur)
			list = list->next;
		output = list->str;
	}
	tputs(restore_cursor, 1, &ft_putchar);
	tputs(clr_eos, 1, &ft_putchar);
	write(1, output, ft_strlen(output));
}

void	press_backspace(char *str, t_hist *hist)
{
	int		cur;
	char	*line;
	int		i;
	t_str	*list;

	if (hist->cur != hist->last + 1)
	{
		i = 0;
		list = hist->list;
		while (++i < hist->cur)
			list = list->next;
		line = list->str;
	}
	else
		line = str;
	cur = ft_strlen(line);
	cur = (cur > 0) * cur;
	if (cur)
		line[cur - 1] = '\0';
	if (!cur)
		return ;
	tputs(cursor_left, 1, &ft_putchar);
	tputs(delete_character, 1, &ft_putchar);
}

char	*ret_str(char *str, t_hist *hist)
{
	int		i;
	char	*res;

	if (hist->cur == hist->last + 1)
		return (str);
	i = 0;
	while (++i < hist->cur)
		hist->list = hist->list->next;
	res = ft_strcat(ft_strdup(hist->list->str), str);
	free(str);
	return (res);
}

int		press_key(char *buf, char *str, t_hist *hist)
{
	if (!ft_strncmp(buf, "\e[A", ft_strlen("\e[A")))
		print_prev(hist);
	else if (!ft_strncmp(buf, "\e[B", ft_strlen("\e[B")))
		print_next(hist, str);
	else if (!ft_strncmp(buf, "\177", 1))
		press_backspace(str, hist);
	else if (!ft_strcmp(buf, "\e[C") || !ft_strcmp(buf, "\e[D"))
		return (1);
	else
		return (0);
	return (1);
}

char	*read_line(t_hist *hist)
{
	struct termios	term;
	char			buf[200];
	int				l;
	char			*str;

	init_save_term(&term);
	buf[0] = '\0';
	str = ft_strdup("");
	tputs(save_cursor, 1, ft_putchar);
	while (ft_strncmp(buf, "\n", 1))
	{
		l = read(0, buf, 100);
		buf[l] = '\0';
		if (!press_key(buf, str, hist))
		{
			write(1, buf, l);
			if (buf[l - 1] != '\n' && (buf[l - 1] != '\4' || !ft_strlen(str)))
				str = ft_strcat(str, buf);
		}
		if (!ft_strcmp(buf, "\4") && ft_strlen(str) == 1)
			break ;
	}
	return (ret_str(str, hist));
}
