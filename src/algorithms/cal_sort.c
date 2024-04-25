/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:55:07 by spenning          #+#    #+#             */
/*   Updated: 2024/04/25 14:38:30 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	best_move_index(int *move_cost, int size_b)
{
	int	index;
	int	value;
	int	ret_index;

	index = 0;
	value = move_cost[index];
	ret_index = 0;
	while (index < size_b)
	{
		if (move_cost[index] < value)
		{
			value = move_cost[index];
			ret_index = index;
		}
		index++;
	}
	return (ret_index);
}

int	cal_best_move_index(int*a, int*b, int size_b)
{
	int	index;
	int	*move_cost;
	int	move_index;

	index = 0;
	move_cost = malloc(sizeof(int) * size_b);
	if (move_cost == NULL)
		return (-1);
	while (index < size_b)
	{
		if (a[index] >= 0 && b[index] >= 0)
			move_cost[index] = max(a[index], b[index]);
		if (a[index] < 0 && b[index] >= 0)
			move_cost[index] = (a[index] * -1) + b[index];
		if (a[index] >= 0 && b[index] < 0)
			move_cost[index] = a[index] + (b[index] * -1);
		if (a[index] < 0 && b[index] < 0)
			move_cost[index] = min(a[index], b[index]) * -1;
		index++;
	}
	move_index = best_move_index(move_cost, size_b);
	free(move_cost);
	return (move_index);
}

int	cal_moves(t_pslist **stack_a, t_pslist **stack_b)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	move_index;

	size_a = ps_lstsize((*stack_a));
	size_b = ps_lstsize((*stack_b));
	a = malloc(sizeof(int) * size_b);
	b = malloc(sizeof(int) * size_b);
	if (a == NULL || b == NULL)
		return (-1);
	cal_a(a, stack_a, stack_b, size_a);
	cal_b(b, stack_b, size_b);
	move_index = cal_best_move_index(a, b, size_b);
	if (move_index == -1)
	{
		free(a);
		free(b);
		return (-1);
	}
	execute_move(stack_a, stack_b, a[move_index], b[move_index]);
	free(a);
	free(b);
	return (0);
}

int	cal_sort(t_pslist **stack_a, t_pslist **stack_b)
{
	int	len;
	int	ret;

	len = ps_lstsize((*stack_a));
	if(lis(stack_a))
		return(EXIT_FAILURE);
	ret = 0;
	push_b_lis(stack_a, stack_b, ps_lstsize((*stack_a)));
	while (!check_n_sorted(stack_a, len, '+'))
	{
		ret = cal_moves(stack_a, stack_b);
		if (ret == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
