/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:33:39 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 19:13:14 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IN_H
# define BUILD_IN_H

# include "main_struct.h"
# include "exit_error.h"
# include "deletes.h"

int		build_in(t_com *com, t_envp *envp);
int		echo_com(t_com *com);
void	exit_com(void);
void	change_errno(t_envp *envp, int err);
int		export_com(t_com *com, t_envp *env);
void	export_out(t_envp *envp);
int		count_args(t_com *com);
int		unset_com(t_com *com, t_envp **envp);
void	delete_history(t_hist *hist);
char	**ft_split_envp(char *str, char c);

#endif
