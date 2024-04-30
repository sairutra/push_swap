/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:24:37 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:36:46 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_max_index(t_pslist **stack_a)
{
	int			max;
	t_pslist	*temp;

	temp = (*stack_a);
	max = temp->index;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	temp = (*stack_a);
	while (temp != NULL)
	{
		if (temp->index == max)
			temp->lds = 1;
		temp = temp->next;
	}
	return (max);
}

void	ds(t_pslist **stack_a, int max, int n)
{
	t_pslist	*temp;
	int			index;

	temp = (*stack_a);
	index = 0;
	if (n <= 0)
		return ;
	while (temp->index != max && index < n && temp != NULL)
	{
		if (temp ->index == max - 1)
			temp->lds = 1;
		index++;
		temp = temp->next;
	}
	ds(stack_a, max - 1, index -1);
	return ;
}

void	lds(t_pslist**stack_a)
{
	int	max;

	max = get_max_index(stack_a);
	ds(stack_a, max, ps_lstsize((*stack_a)));
}

int	push_b(t_pslist **stack_a, t_pslist **stack_b, int n)
{
	int	index;
	int	moves;

	moves = 0;
	index = 0;
	while (index < n)
	{
		if ((*stack_a)->lds == 0)
		{
			push(stack_a, stack_b, pa);
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

void	recurse_sort(t_pslist **stack_a, t_pslist **stack_b)
{
	int			max;
	t_moves		*moves;
	t_pslist	**stacks[2];

	stacks[0] = stack_a;
	stacks[1] = stack_b;
	sort_index(stack_a);
	max = calc_max(stack_a);
	moves = mv_lstnew(nm);
	recurse(max, stacks, &moves, ps_lstsize((*stack_a)));
	print_t_moves(moves);
}
