/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:47:06 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/12 00:05:07 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		main(int argc, char **argv, char **envp)
{
	t_hist	hist;

	copy_envp(&hist, envp);
	start(&hist);
	return (0);
}
