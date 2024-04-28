/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:24:37 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 19:39:40 by spenning         ###   ########.fr       */
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
	int	max;
	int	*moves;

	ft_printf("start\n----------\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("----------\n");
	sort_index(stack_a);
	max = calc_max(stack_a);
	ft_printf("max: %d\n", max);
	moves = malloc(sizeof(int) * max);
	if (moves == NULL)
		exit(EXIT_FAILURE);

	ft_printf("max: %d\n", max);
	ft_printf("end\n----------\n");
	print_index_lis_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("----------\n");
	for (int i = max; i > 0; i--)
	{
		if(moves[i] == mpa)
			ft_printf("pa\n");
		if(moves[i] == mpb)
			ft_printf("pb\n");
		if(moves[i] == mra)
			ft_printf("ra\n");
		if(moves[i] == mrb)
			ft_printf("rb\n");
		if(moves[i] == mrr)
			ft_printf("rr\n");
		if(moves[i] == mrra)
			ft_printf("rra\n");
		if(moves[i] == mrrr)
			ft_printf("rrr\n");
		if(moves[i] == msa)
			ft_printf("sa\n");
		if(moves[i] == msb)
			ft_printf("sb\n");
		if(moves[i] == mss)
			ft_printf("ss\n");
	}

}
