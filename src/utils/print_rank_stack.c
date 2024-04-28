/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rank_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:37:40 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:37:47 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_rank_stack(t_pslist	**stack, char name)
{
	t_pslist	*temp;

	temp = (*stack);
	ft_printf("stack: %c \n", name);
	while (temp != NULL)
	{
		ft_printf("content:%d ranking:%d \n", temp->content, temp->rrank);
		temp = temp->next;
	}
	ft_printf("\n");
}
