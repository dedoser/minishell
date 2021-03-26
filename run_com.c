/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:58:46 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/26 21:33:41 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funcs.h"

int		open_input(t_com *com)
{
	int	err;

	err = 1;
	while (com->in_files)
	{
		com->in_files = com->in_files->next;
		if (com->in_fd = open(com->in_files->line, O_RDONLY, S_IREAD) < 0)
		{
			err = 0;
			printf("%s: No such file or directory\n", com->in_files->line);
		}
		com->in_files = com->in_files->next;
	}
	return (err);
}

int		open_output(t_com *com)
{
	int		type;
	int		flag;
	int		err;

	err = 1;
	while (com->out_files)
	{
		type = ft_strcmp(com->out_files->line, ">") == 0;
		com->out_files = com->out_files->next;
		flag = O_CREAT | O_APPEND * !type | O_TRUNC * type | O_WRONLY;
		if (com->out_fd = open(com->in_files->line, flag, S_IWRITE) < 0)
		{
			err = 0;
			printf("%s: No such file or directory\n", com->out_files->line);
		}
		com->out_files = com->out_files->next;
	}
	return (err);
}

void	run_com(t_com **com)
{
	int		i;

	i = 0;
	while (com[i])
	{
		if (!open_redirects(com[i]))
			continue;
		launch_com(com[i]);
		++i;
	}
	
}
