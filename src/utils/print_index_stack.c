/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:36:45 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:36:56 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_index_stack(t_pslist	**stack, char name)
{
	t_pslist	*temp;

	temp = (*stack);
	ft_printf("stack: %c \n", name);
	while (temp != NULL)
	{
		ft_printf("content:%d index:%d \n", temp->content, temp->index);
		temp = temp->next;
	}
	ft_printf("\n");
}
