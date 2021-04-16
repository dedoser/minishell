/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:23:44 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:20:52 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

static char	*get_str_and_prompt(t_hist *hist)
{
	char	*str;

	signal(SIGINT, sigint_react);
	write(1, "beautiful shell$ ", 17);
	g_var.hist = history_copy(hist);
	str = read_line(g_var.hist);
	delete_temp_history(g_var.hist);
	return (str);
}

static void	send_str_to_launch(char *str, t_hist *hist, t_com **com)
{
	com = parse_com(str, hist->envp);
	g_var.com = com;
	run_com(com, hist->envp);
	delete_com(com);
}

static void	start_shell(t_hist *hist, char *str, t_com **com)
{
	while (1)
	{
		str = get_str_and_prompt(hist);
		if (str && !ft_strncmp(str, "\4", 1))
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (ft_strlen(str))
		{
			add_line(hist, str);
			if (!check_line(str))
			{
				write(2,
					"beautiful shell$: syntax error near unexpected token `;\'\n",
					57);
				continue ;
			}
			send_str_to_launch(str, hist, com);
		}
	}
}

void	start(t_hist *hist)
{
	t_com	**com;
	char	*str;

	com = NULL;
	str = NULL;
	start_shell(hist, str, com);
	delete_history(hist);
}
