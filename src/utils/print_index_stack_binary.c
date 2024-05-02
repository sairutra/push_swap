/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index_stack_binary.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:36:45 by spenning          #+#    #+#             */
/*   Updated: 2024/05/02 14:17:03 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// void	print_binary(int content)
// {
// 	int index;

// 	index = 0;
// 	ft_printf("binary: ");
// 	while (index < 8)
// 	{
// 		ft_printf("%d", !!((content << index) & 0x80));
// 		index++;
// 	}
// 	ft_printf("\n");
// }


void	print_index_stack_binary(t_pslist	**stack, char name)
{
	t_pslist	*temp;

	temp = (*stack);
	ft_printf("stack: %c \n", name);
	while (temp != NULL)
	{
		ft_printf("content:%d index:%d binary:%d\n", temp->content, temp->index, temp->binary);
		temp = temp->next;
	}
}

