/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:33:00 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 16:35:06 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	bubble_sort(t_pslist	**stack_a, t_pslist	**stack_b)
{
	int	len;

	len = ps_lstsize((*stack_a));
	while (!check_n_sorted(stack_a, len, '+'))
	{
		if ((*stack_b) == NULL || (*stack_a)-> content > (*stack_b)->content)
			push(stack_a, stack_b, pa);
		if ((*stack_a)-> content < (*stack_b)->content)
		{
			push(stack_b, stack_a, pb);
			swap(stack_a, sa);
		}
		if (check_sorted_stack(stack_a, stack_b))
		{
			while ((*stack_b) != NULL)
				push(stack_b, stack_a, pb);
		}
	}
}
