/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:47:06 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/27 17:06:20 by fignigno         ###   ########.fr       */
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
}

int		main(int argc, char **argv, char **envp)
{
	t_hist			hist;
	struct termios	term;

	if (argc > 1 && !argv[0])
		return (0);
	copy_envp(&hist, envp);
	init_hist(&hist);
	init_save_term(&term);
	start(&hist);
	tcsetattr(0, TCSANOW, &term);
	return (0);
}
