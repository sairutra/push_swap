/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:15:10 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:37:59 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse(int max, t_pslist **stacks[], t_moves **moves, int size)
{
	int	succesful;

	succesful = 0;
	if (ps_lstsize((*stacks[stacka])) == size)
	{
		if (check_n_sorted(stacks[stacka], size, '+'))
			return (1);
	}
	if (max < 1)
		return (0);
	rotate_np(stacks[stacka]);
	mv_lstadd_back(moves, mv_lstnew(mra));
	succesful = recurse(max - 1, stacks, moves, size);
	if (!succesful)
		succesful = recurse_rotate(max - 1, stacks, moves, size);
	if (!succesful)
		succesful = recurse_swap(max - 1, stacks, moves, size);
	if (!succesful)
	{
		mv_dellast(moves);
		un_sswap_np(stacks[stacka], stacks[stackb]);
	}
	return (succesful);
}
