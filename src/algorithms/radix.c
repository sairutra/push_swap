/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:45:34 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 17:02:46 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	get_max_bits(t_pslist **stack)
{
	t_pslist	*temp;
	int			max;
	int			max_bits;

	temp = (*stack);
	max = temp->index;
	max_bits = 0;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_pslist	**stack_a, t_pslist	**stack_b)
{
	int	index;
	int	inindex;
	int	size;

	index = 0;
	inindex = 0;
	size = ps_lstsize(*stack_a);
	while (index < get_max_bits(stack_a))
	{
		while (inindex < size)
		{
			if ((((*stack_a)->index >> index) & 1) == 1)
				rotate(stack_a, ra);
			else
				push(stack_a, stack_b, pb);
			inindex++;
		}
		inindex = 0;
		while ((*stack_b) != NULL)
			push(stack_b, stack_a, pa);
		index++;
	}
}
