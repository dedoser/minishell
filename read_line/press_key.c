/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:13:40 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 19:40:45 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read_line.h"

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
	hist->mod = 0;
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
	hist->mod = 0;
	tputs(restore_cursor, 1, &ft_putchar);
	tputs(clr_eos, 1, &ft_putchar);
	write(1, output, ft_strlen(output));
}

void	move_cursor(char *line)
{
	int		w;
	int		h;
	size_t	len;
	int		i;

	w = tgetnum("co");
	h = tgetnum("li");
	len = ft_strlen(line);
	if (len + 1 == w - ft_strlen("beautiful shell$ "))
	{
		tputs(cursor_up, 1, &ft_putchar);
		i = -1;
		while (++i < w)
			tputs(cursor_right, 1, &ft_putchar);
	}
	else
		tputs(cursor_left, 1, &ft_putchar);
	tputs(delete_character, 1, &ft_putchar);
}

void	press_backspace(char *str, t_hist *hist)
{
	int		cur;
	char	*line;
	int		i;
	t_str	*list;

	if (hist->cur <= hist->last && hist->last != 0)
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
	move_cursor(line);
}

int	press_key(char *buf, char *str, t_hist *hist)
{
	if (!ft_strncmp(buf, "\e[A", ft_strlen("\e[A")))
		print_prev(hist);
	else if (!ft_strncmp(buf, "\e[B", ft_strlen("\e[B")))
		print_next(hist, str);
	else if (!ft_strncmp(buf, "\177", 1))
		press_backspace(str, hist);
	else if (!ft_strcmp(buf, "\e[C") || !ft_strcmp(buf, "\e[D"))
		return (1);
	else if (!ft_strcmp(buf, "\t"))
		return (1);
	else if (buf[0] == (char)8)
		return (1);
	else
		return (0);
	return (1);
}
