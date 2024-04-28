/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:15:10 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:16:36 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	swap_check(t_pslist **stack)
{
	int			elm;
	t_pslist	*head;

	head = (*stack);
	elm = 0;
	while ((*stack))
	{
		elm++;
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
	return (elm);
}

void	swap(t_pslist	**stack, int print)
{
	t_pslist	*temp;

	if (swap_check(stack) < 2)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	(*stack) = temp;
	if (print == sa)
		ft_printf("sa\n");
	if (print == sb)
		ft_printf("sb\n");
}

void	sswap(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_printf("ss\n");
	swap(stack_a, ss);
	swap(stack_b, ss);
}
