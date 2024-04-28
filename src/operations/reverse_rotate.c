/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:13:10 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:13:56 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rev_rotate_print(int print)
{
	if (print == rra)
		ft_printf("rra\n");
	if (print == rrb)
		ft_printf("rrb\n");
}

void	rev_rotate(t_pslist **stack, int print)
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
		rev_rotate_print(print);
		return ;
	}
	second_last = ps_lst_second_last((*stack));
	(*stack) = last;
	last->next = first;
	second_last->next = NULL;
	rev_rotate_print(print);
}

void	rev_rrotate(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_printf("rrr\n");
	rev_rotate(stack_a, rrr);
	rev_rotate(stack_b, rrr);
}
