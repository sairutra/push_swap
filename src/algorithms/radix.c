/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:45:34 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 13:08:02 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result = result * base;
		exponent--;
	}
	return (result);
}

void	add_binary(t_pslist	**stack_a)
{
	int			index;
	int			value;
	t_pslist	*temp;

	value = 0;
	index = 0;
	temp = (*stack_a);
	while (temp != NULL)
	{
		while (index <= 32)
		{
			value = ((temp->index >> index) & 1) * power(10, index);
			temp->binary += value;
			index++;
		}
		index = 0;
		temp = temp->next;
	}
}

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
	sort_index(stack_a);
	add_binary(stack_a);
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
