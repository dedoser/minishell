/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:47:06 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/10 00:52:52 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

void	init_hist(t_hist *hist)
{
	hist->cur = 0;
	hist->last = 0;
	if (!(hist->list = (t_str *)malloc(sizeof(t_list))))
		exit_error("Malloc error");
	hist->list->next = NULL;
	hist->list->str = NULL;
	hist->mod = 0;
	g_var.child_pid = NULL;
	g_var.hist = NULL;
	g_var.cp_hist = hist;
}

void	sigint_react(int sig)
{
	if (sig != SIGINT)
	{
		return ;
	}
	write(1, "\nbeautiful shell$ ", 18);
	tputs(save_cursor, 1, ft_putchar);
	free(g_var.str);
	g_var.str = ft_strdup("");
}

int		main(int argc, char **argv, char **envp)
{
	t_hist			hist;

	if (argc > 1 && !argv[0])
		return (0);
	signal(SIGINT, sigint_react);
	signal(SIGQUIT, SIG_IGN);
	copy_envp(&hist, envp);
	init_hist(&hist);
	init_save_term(&g_var.term);
	start(&hist);
	tcsetattr(0, TCSANOW, &g_var.term);
	return (0);
}
