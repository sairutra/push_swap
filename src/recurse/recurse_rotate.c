/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:36:35 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:38:41 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recu_rev_rotate(int max, t_pslist **stacks[], t_moves **moves, int size)
{
	int	succesful;

	mv_dellast(moves);
	un_rrotate_np(stacks[stacka], stacks[stackb]);
	rev_rotate_np(stacks[stacka]);
	mv_lstadd_back(moves, mv_lstnew(mrra));
	succesful = recurse(max - 1, stacks, moves, size);
	if (!succesful)
	{
		mv_dellast(moves);
		un_rev_rotate_np(stacks[stacka]);
		rev_rotate_np(stacks[stackb]);
		mv_lstadd_back(moves, mv_lstnew(mrrb));
		succesful = recurse(max - 1, stacks, moves, size);
	}
	if (!succesful)
	{
		mv_dellast(moves);
		un_rev_rotate_np(stacks[stackb]);
		rev_rrotate_np(stacks[stacka], stacks[stackb]);
		mv_lstadd_back(moves, mv_lstnew(mrrr));
		succesful = recurse(max - 1, stacks, moves, size);
	}
	return (succesful);
}

int	recurse_rotate(int max, t_pslist **stacks[], t_moves **moves, int size)
{
	int	succesful;

	mv_dellast(moves);
	un_rotate_np(stacks[stacka]);
	rotate_np(stacks[stackb]);
	mv_lstadd_back(moves, mv_lstnew(mrb));
	succesful = recurse(max - 1, stacks, moves, size);
	if (!succesful)
	{
		mv_dellast(moves);
		un_rotate_np(stacks[stackb]);
		rrotate_np(stacks[stacka], stacks[stackb]);
		mv_lstadd_back(moves, mv_lstnew(mrr));
		succesful = recurse(max - 1, stacks, moves, size);
	}
	if (!succesful)
		succesful = recu_rev_rotate(max - 1, stacks, moves, size);
	return (succesful);
}
