/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_build_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:42:25 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/27 22:00:32 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		count_args(t_com *com)
{
	int		i;

	i = 0;
	while (com->args[i])
		++i;
	return (i);
}

void	export_out(t_com *com, t_envp *envp)
{
	sort(create_key_mass(envp));
	//по ключам вывести значения
}

void	export_com(t_com *com, t_envp *env)
{
	if (count_args(com) == 1)
		export_out(com, env);
	else
		export_add(com, env);
}
