/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:24:19 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:24:50 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_pslist	*create_node(char *v)
{
	int			content;
	t_pslist	*node;

	content = ft_atoi(v);
	node = ps_lstnew(content);
	if (node == NULL)
		return (NULL);
	return (node);
}

int	create_stack(t_pslist **llist, char **argv)
{
	int			index;
	t_pslist	*new_node;

	index = 0;
	new_node = create_node(argv[index++]);
	if (new_node == NULL)
		return (EXIT_FAILURE);
	ps_lstadd_back(llist, new_node);
	while (argv[index] != NULL)
	{
		new_node = create_node(argv[index]);
		if (new_node == NULL)
			return (EXIT_FAILURE);
		ps_lstadd_back(llist, new_node);
		index++;
	}
	return (EXIT_SUCCESS);
}
