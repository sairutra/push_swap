/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:18:27 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 17:23:47 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_small_5(t_pslist **stacka, t_pslist **stackb, int size)
{
	while (size > 0)
	{
		if ((*stacka)->index == 0 || (*stacka)->index == 1)
			push(stacka, stackb, pb);
		else
			rotate(stacka, ra);
		size--;
	}
	if ((*stackb)->index == 0)
		swap(stackb, sb);
	if ((*stacka)->next->next->index != 4)
	{
		if ((*stacka)->index == 4)
			rotate(stacka, ra);
		else
			rev_rotate(stacka, rra);
	}
	if ((*stacka)->index > (*stacka)->next->index)
		swap(stacka, sa);
	push(stackb, stacka, pa);
	push(stackb, stacka, pa);
}

void	sort_small_4(t_pslist **stacka, t_pslist **stackb, int size)
{
	while (size > 0)
	{
		if ((*stacka)->index == 0 || (*stacka)->index == 1)
			push(stacka, stackb, pb);
		else
			rotate(stacka, ra);
		size--;
	}
	if ((*stackb)->index == 0)
		swap(stackb, sb);
	if ((*stacka)->next->index != 4)
	{
		if ((*stacka)->index == 4)
			rotate(stacka, ra);
		else
			rev_rotate(stacka, rra);
	}
	if ((*stacka)->index > (*stacka)->next->index)
		swap(stacka, sa);
	push(stackb, stacka, pa);
	push(stackb, stacka, pa);
}

void	sort_small_3(t_pslist **stacka)
{
	if ((*stacka)->next->next->index != 2)
	{
		if ((*stacka)->index == 2)
			rotate(stacka, ra);
		else
			rev_rotate(stacka, rra);
	}
	if ((*stacka)->index > (*stacka)->next->index)
		swap(stacka, sa);
}

void	sort_small_2(t_pslist **stacka)
{
	if (!check_n_sorted(stacka, 2, 'a'))
		rotate(stacka, 'a');
}

void	sort_small(t_pslist **stacka, t_pslist **stackb)
{
	int	size;

	size = ps_lstsize((*stacka));
	if (size == 2)
		sort_small_2(stacka);
	if (size == 3)
		sort_small_3(stacka);
	if (size == 4)
		sort_small_4(stacka, stackb, size);
	if (size == 5)
		sort_small_5(stacka, stackb, size);
}
