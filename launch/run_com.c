/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:58:46 by fignigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:17:14 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch.h"

static int	open_input(t_com *com)
{
	int		err;
	t_arg	*arg;

	err = 1;
	while (com)
	{
		arg = com->in_files;
		while (arg)
		{
			arg = arg->next;
			com->in_fd = open(arg->line, O_RDONLY, 0666);
			if (com->in_fd < 0)
			{
				err = 0;
				printf("%s: No such file or directory\n", arg->line);
			}
			arg = arg->next;
		}
		com = com->next;
	}
	return (err);
}

static int	open_output(t_com *com)
{
	int		type;
	int		flag;
	int		err;
	t_arg	*arg;

	err = 1;
	while (com)
	{
		arg = com->out_files;
		while (arg)
		{
			type = ft_strcmp(arg->line, ">") == 0;
			arg = arg->next;
			flag = O_CREAT | O_APPEND * !type | O_TRUNC * type | O_WRONLY;
			com->out_fd = open(arg->line, flag, 0666);
			if (com->out_fd < 0)
			{
				err = 0;
				printf("%s: No such file or directory\n", arg->line);
			}
			arg = arg->next;
		}
		com = com->next;
	}
	return (err);
}

void	run_com(t_com **com, t_envp *envp)
{
	int		i;

	i = -1;
	while (com[++i])
	{
		if ((!com[i]->list && !com[i]->in_files && !com[i]->out_files)
			|| !open_input(com[i]) || !open_output(com[i]))
			continue ;
		if (com[i]->args)
			launch_com(com[i], envp);
	}
}
