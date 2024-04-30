/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:36:14 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:39:12 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse_swap(int max, t_pslist **stacks[], t_moves **moves, int size)
{
	int	succesful;

	mv_dellast(moves);
	un_rev_rrotate_np(stacks[stacka], stacks[stackb]);
	swap_np(stacks[stacka]);
	mv_lstadd_back(moves, mv_lstnew(msa));
	succesful = recurse(max - 1, stacks, moves, size);
	if (!succesful)
	{
		mv_dellast(moves);
		un_swap_np(stacks[stacka]);
		swap_np(stacks[stackb]);
		mv_lstadd_back(moves, mv_lstnew(msb));
		succesful = recurse(max - 1, stacks, moves, size);
	}
	if (!succesful)
	{
		mv_dellast(moves);
		un_swap_np(stacks[stackb]);
		sswap_np(stacks[stacka], stacks[stackb]);
		mv_lstadd_back(moves, mv_lstnew(mss));
		succesful = recurse(max - 1, stacks, moves, size);
	}
	return (succesful);
}
