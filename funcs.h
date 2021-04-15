/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:18 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 18:31:29 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "main_struct.h"

void	exit_error(const char *str);
void	go_further(char *str, char c, int *i);
void	copy_envp(t_hist *hist, char **envp);
void	start(t_hist *hist);
t_com	**parse_com(char *str, t_envp *envp);
char	*copy_further(char *dst, char *src, char c);
void	add_str(t_arg **lst, char *str, int is_space);
int		is_special_char(char c);
char	*quote_found(char **str, char quote);
char	*spec_found(char **str, char *prev);
void	main_parcing(t_com *com, t_envp *envp);
char	*redirect_found(char **str);
char	*pipe_found(void);
void	paste_envp(t_arg *args, t_envp *envp);
void	delete_protecting(t_arg *arg);
char	**create_final_mass(t_arg *arg);
void	change_spaces(t_arg *arg);
void	init_save_term(struct termios *term);

void	run_com(t_com **com, t_envp *envp);
void	find_com(t_com *com, t_envp *env);
void	launch_com(t_com *com, t_envp *envp);
void	export_out(t_envp *envp);
char	**ft_split_envp(char *str, char c);
int		export_com(t_com *com, t_envp *env);
int		unset_com(t_com *com, t_envp **envp);
void	exit_com(void);
int		build_in(t_com *com, t_envp *envp);
void	delete_history(t_hist *hist);
void	sigint_react(int sig);
void	change_errno(t_envp *envp, int err);
void	delete_com(t_com **com);
int		ft_putchar(int c);
void	delete_mass(char **mass);
void	delete_com(t_com **com);
void	alloc_check(void *ptr);
#endif
