/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_np.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:17:51 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:18:41 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	push_np(t_pslist **stack_1, t_pslist **stack_2)
{
	t_pslist	*temp1_a;
	t_pslist	*temp1_b;

	if (!(*stack_1))
		return ;
	temp1_a = (*stack_1);
	temp1_b = (*stack_1)->next;
	temp1_a->next = (*stack_2);
	(*stack_2) = temp1_a;
	(*stack_1) = temp1_b;
}

void	un_push_np(t_pslist **stack_1, t_pslist **stack_2)
{
	t_pslist	*temp1_a;
	t_pslist	*temp1_b;

	if (!(*stack_1))
		return ;
	temp1_a = (*stack_1);
	temp1_b = (*stack_1)->next;
	temp1_a->next = (*stack_2);
	(*stack_2) = temp1_a;
	(*stack_1) = temp1_b;
}
