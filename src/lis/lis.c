/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:32:59 by spenning          #+#    #+#             */
/*   Updated: 2024/04/25 19:08:13 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// int	len_is(int *stack_c, int len)
// {
// 	int	index;
// 	int	inner_index;
// 	int	value;
// 	int size;

// 	size = 0;
// 	index = len;
// 	inner_index = index;
// 	while (index >= 0)
// 	{
// 		value = stack_c[index];
// 		while (inner_index <= len)
// 		{
// 			if (stack_c[inner_index] > value)
// 			{
// 				value = stack_c[inner_index];
// 				size += 1;
// 			}
// 			inner_index++;
// 		}
// 		index--;
// 		inner_index = index;
// 	}
// 	return (size);
// }

void	is(int *stack_c, int *lis, int len)
{
	int	index;
	int	inner_index;
	int	value;

	index = len;
	inner_index = index;
	while (index >= 0)
	{
		value = stack_c[index];
		while (inner_index <= len)
		{
			if (stack_c[inner_index] > value)
			{
				value = stack_c[inner_index];
				lis[index] += 1;
			}
			inner_index++;
		}
		index--;
		inner_index = index;
	}
}

void	init_lis_stack(t_pslist **stack_a)
{
	t_pslist	*temp;
	int			val;

	temp = (*stack_a);
	temp->lis = 1;
	val = temp->content;
	while (temp != NULL)
	{
		if (temp->content > val)
		{
			val = temp->content;
			temp->lis = 1;
		}
		temp = temp->next;
	}
}

void	init_lis(t_pslist **stack_a, int *lis, int len)
{
	int			index;
	int			max;
	int			index_of_max;
	t_pslist	*temp;

	temp = (*stack_a);
	index = 0;
	max = lis[0];
	index_of_max = 0;
	while (index < len)
	{
		if (lis[index] > max)
		{
			max = lis[index];
			index_of_max = index;
		}
		index++;
	}
	while (index_of_max > 0)
	{
		temp = temp->next;
		index_of_max--;
	}
	init_lis_stack(&temp);
}

int	lis(t_pslist**stack_a)
{
	int	*stack_c;
	int	*lis;
	int	len;

	len = ps_lstsize((*stack_a)) - 1;
	lis = ft_calloc(sizeof(int), len);
	if (lis == NULL)
		return (EXIT_FAILURE);
	stack_c = ft_calloc(sizeof(int), ps_lstsize((*stack_a)));
	init_c(stack_a, stack_c);
	is(stack_c, lis, len);
	free(stack_c);
	init_lis(stack_a, lis, len);
	free(lis);
	return (EXIT_SUCCESS);
}

int	push_b_lis(t_pslist **stack_a, t_pslist **stack_b, int n)
{
	int	index;
	int	moves;

	moves = 0;
	index = 0;
	while (index < n)
	{
		if ((*stack_a)->lis == 0)
		{
			push(stack_a, stack_b, pb);
			moves++;
		}
		else
		{
			rotate(stack_a, ra);
			moves++;
		}
		index++;
	}
	return (moves);
}
