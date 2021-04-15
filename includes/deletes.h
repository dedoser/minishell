/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:11:05 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/15 19:39:55 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELETES_H
# define DELETES_H

# include "main_struct.h"

void	delete_mass(char **mass);
void	delete_com(t_com **com);
void	delete_temp_history(t_hist *hist);

#endif
