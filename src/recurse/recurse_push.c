/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:05 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:39:04 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse_push(int max, t_pslist **stacks[], t_moves **moves, int size)
{
	int	succesful;

	mv_dellast(moves);
	un_sswap_np(stacks[stacka], stacks[stackb]);
	push_np(stacks[stacka], stacks[stackb]);
	mv_lstadd_back(moves, mv_lstnew(mpb));
	succesful = recurse(max - 1, stacks, moves, size);
	if (!succesful)
	{
		mv_dellast(moves);
		un_push_np(stacks[stackb], stacks[stacka]);
		push_np(stacks[stackb], stacks[stacka]);
		mv_lstadd_back(moves, mv_lstnew(mpa));
		succesful = recurse(max - 1, stacks, moves, size);
	}
	if (!succesful)
	{
		mv_dellast(moves);
		un_push_np(stacks[stacka], stacks[stackb]);
	}
	return (succesful);
}
