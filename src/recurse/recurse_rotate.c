/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:36:35 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 19:38:24 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recu_rev_rotate(int max, t_pslist**sa, t_pslist **sb, int *moves, int size)
{
	int	succesful;

	moves[max -1] = nm;
	un_rrotate_np(sa, sb);
	rev_rotate_np(sa);
	moves[max] = mrra;
	succesful = recurse(max - 1, sa, sb, moves, size);
	if (!succesful)
	{
		moves[max -1] = nm;
		un_rev_rotate_np(sa);
		rev_rotate_np(sb);
		moves[max] = mrrb;
		succesful = recurse(max - 1, sa, sb, moves, size);
	}
	if (!succesful)
	{
		moves[max -1] = nm;
		un_rev_rotate_np(sb);
		rev_rrotate_np(sa, sb);
		moves[max] = mrrr;
		succesful = recurse(max - 1, sa, sb, moves, size);
	}
	return (succesful);
}

int	recurse_rotate(int max, t_pslist**sa, t_pslist **sb, int *moves, int size)
{
	int	succesful;

	moves[max -1] = nm;
	un_rotate_np(sa);
	rotate_np(sb);
	moves[max] = mrb;
	succesful = recurse(max - 1, sa, sb, moves, size);
	if (!succesful)
	{
		moves[max -1] = nm;
		un_rotate_np(sb);
		rrotate_np(sa, sb);
		moves[max] = mrr;
		succesful = recurse(max - 1, sa, sb, moves, size);
	}
	if (!succesful)
		succesful = recu_rev_rotate(max - 1, sa, sb, moves, size);
	return (succesful);
}
