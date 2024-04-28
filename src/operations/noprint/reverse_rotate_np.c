/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_np.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:18:52 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:19:19 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

void	rev_rotate_np(t_pslist **stack)
{
	t_pslist	*first;
	t_pslist	*last;
	t_pslist	*second_last;
	int			lstsize;

	first = (*stack);
	last = ps_lstlast((*stack));
	lstsize = ps_lstsize((*stack));
	if (lstsize <= 1)
		return ;
	if (lstsize == 2)
	{
		(*stack) = last;
		last->next = first;
		(*stack)->next->next = NULL;
		return ;
	}
	second_last = ps_lst_second_last((*stack));
	(*stack) = last;
	last->next = first;
	second_last->next = NULL;
}

void	rev_rrotate_np(t_pslist **stack_a, t_pslist **stack_b)
{
	rev_rotate_np(stack_a);
	rev_rotate_np(stack_b);
}

void	un_rev_rotate_np(t_pslist **stack)
{
	rotate_np(stack);
}

void	un_rev_rrotate_np(t_pslist **stack_a, t_pslist **stack_b)
{
	rrotate_np(stack_a, stack_b);
}
