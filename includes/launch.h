/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:32:43 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 19:15:15 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_H
# define LAUNCH_H

# include "main_struct.h"
# include "parser.h"
# include "read_line.h"
# include "build_in.h"
# include "exit_error.h"
# include "deletes.h"

t_hist	*history_copy(t_hist *hist);
void	add_line(t_hist *hist, char *str);
void	start(t_hist *hist);
void	fork_start(t_com *com, t_envp *envp);
char	**make_mass_envp(t_envp *envp);
void	launch_com(t_com *com, t_envp *envp);
void	init_hist(t_hist *hist);
void	sigint_react(int sig);
void	run_com(t_com **com, t_envp *envp);
void	copy_envp(t_hist *hist, char **envp);

#endif
