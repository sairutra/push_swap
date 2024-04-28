/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index_lis_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:35:42 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:36:40 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_index_lis_stack(t_pslist	**stack, char name)
{
	t_pslist	*temp;

	temp = (*stack);
	ft_printf("stack: %c \n", name);
	while (temp != NULL)
	{
		ft_printf("content:%d ", temp->content);
		ft_printf("index:%d \n", temp->index);
		ft_printf("lis: %d\n", temp->lis);
		temp = temp->next;
	}
	ft_printf("\n");
}
