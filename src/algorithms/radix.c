/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:45:34 by spenning          #+#    #+#             */
/*   Updated: 2024/05/02 18:47:50 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_array(int *array)
{
	int	index;

	index = 0;
	while (index < 10)
	{
		if (array[index] != 0)
			return (0);
		index++;
	}
	return (1);
}

void	count_ranking(int *array, t_pslist	**stack)
{
	t_pslist	*temp;

	ft_memset(array, 0, sizeof(int) * 2);
	temp = (*stack);
	while (temp != NULL)
	{
		array[temp->rrank] += 1;
		temp = temp->next;
	}
}

int	recurse_rank(int content, int depth, int base)
{
	depth = depth - 1;
	if (depth == 0)
		return (content % base);
	return (recurse_rank(content / 2, depth, base));
}

void	give_ranking(t_pslist	**stack, int depth, int base)
{
	t_pslist	*temp;

	temp = (*stack);
	while (temp != NULL)
	{
		temp->rrank = recurse_rank(temp->binary, depth, base);
		temp = temp->next;
	}
}


int power (int base, int exponent)
{
	int result;

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
	int index;
	int value;
	t_pslist *temp;

	value = 0;
	index = 0;
	temp = (*stack_a);
	while(temp != NULL)
	{
		while (index < 8)
		{
			value = ((temp->index >> index) & 1) * power(10, index);
			temp->binary += value; 
			index++; 
		}
		index = 0;
		temp = temp->next;
	}
}



void	radix(t_pslist	**stack_a, t_pslist	**stack_b)
{
	int index;
	int jindex;
	int size;
	int	max_bit;

	index = 0;
	jindex = 0;
	sort_index(stack_a);
	add_binary(stack_a);
	// max_bit = get_max_bits(stack_a);
	max_bit = ndigits((*stack_a)) + 1;
	ft_printf("maxbit: %d\n", max_bit);
	size = ps_lstsize(*stack_a);
	while (index < max_bit)
	{
		// ft_printf("size: %d\n", size);
		// ft_printf("size: %d\n", max_bit);
		while(jindex < size)
		{
			if((((*stack_a)->index >> index) & 1) == 1)
				rotate(stack_a, ra);
			else
				push(stack_a, stack_b, pb);
			jindex++;
		}
		jindex = 0;
		while ((*stack_b) != NULL)
			push(stack_b, stack_a, pa);
		index++;
	}
	// print_stack(stack_a, 'a');
}
