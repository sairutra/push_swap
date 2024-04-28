/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:55:07 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 16:38:13 by spenning         ###   ########.fr       */
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
	if (size_b == 0)
		return (0);
	move_cost = ft_calloc(sizeof(int), size_b);
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

// calculate what the shortest route is ra or rra
void	rotate_a(t_pslist **sa)
{
	while (!check_n_sorted(sa, ps_lstsize((*sa)), '+'))
		rotate(sa, ra);
}

int	cal_moves(t_pslist **stack_a, t_pslist **stack_b)
{
	int	*a;
	int	*b;
	int	size_b;
	int	move_index;

	size_b = ps_lstsize((*stack_b));
	a = ft_calloc(sizeof(int), size_b);
	b = ft_calloc(sizeof(int), size_b);
	if (a == NULL || b == NULL)
		return (-1);
	cal_a(a, stack_a, stack_b, ps_lstsize((*stack_a)));
	cal_b(b, stack_b, size_b);
	move_index = cal_best_move_index(a, b, size_b);
	if (move_index == -1)
	{
		free2(a, b);
		return (-1);
	}
	if ((*stack_b) == NULL)
		rotate_a(stack_a);
	else
		execute_move(stack_a, stack_b, a[move_index], b[move_index]);
	free2(a, b);
	return (0);
}

int	cal_sort(t_pslist **stack_a, t_pslist **stack_b)
{
	int	len;
	int	ret;

	len = ps_lstsize((*stack_a));
	ret = lis(stack_a);
	if (ret)
		return (EXIT_FAILURE);
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
