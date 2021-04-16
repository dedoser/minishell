/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:21:58 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:24:37 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "main_struct.h"
# include "exit_error.h"
# include "deletes.h"

int		check_files(t_com *com);
int		check_pipes(t_arg *list);
int		create_com(t_com *com);
char	**create_final_mass(t_arg *arg);
void	delete_protecting(t_arg *arg);
t_com	**parse_com(char *str, t_envp *envp);
void	find_com(t_com *com, t_envp *env);
char	*spec_found(char **str, char *prev);
char	*quote_found(char **str, char quote);
void	go_further(char *str, char c, int *i);
void	add_str(t_arg **lst, char *str, int is_space);
void	change_spaces(t_arg *arg);
void	paste_envp(t_arg *args, t_envp *envp);
char	*redirect_found(char **str);
char	*pipe_found(void);
void	main_parcing(t_com *com, t_envp *envp);
void	make_redirect(t_com *com);
void	pass_redirect(t_com *com);

#endif
