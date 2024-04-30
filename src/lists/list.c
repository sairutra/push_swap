/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:10:08 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 13:35:44 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_pslist	*ps_lstnew(int content)
{
	t_pslist	*new_node;

	new_node = ft_calloc(sizeof(t_pslist), 1);
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_moves	*mv_lstnew(int content)
{
	t_moves	*new_node;

	new_node = ft_calloc(sizeof(t_moves), 1);
	if (new_node == NULL)
		return (NULL);
	new_node->move = content;
	new_node->next = NULL;
	return (new_node);
}
