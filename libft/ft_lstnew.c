/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:37:36 by fignigno          #+#    #+#             */
/*   Updated: 2020/10/31 19:39:45 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *res;

	if ((res = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	res->next = NULL;
	res->content = content;
	return (res);
}
