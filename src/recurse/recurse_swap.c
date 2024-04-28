/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:36:14 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 19:38:59 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse_swap(int max, t_pslist**sa, t_pslist **sb, int *moves, int size)
{
	int	succesful;

	moves[max -1] = nm;
	un_rev_rrotate_np(sa, sb);
	swap_np(sa);
	moves[max] = msa;
	succesful = recurse(max - 1, sa, sb, moves, size);
	if (!succesful)
	{
		moves[max -1] = nm;
		un_swap_np(sa);
		swap_np(sb);
		moves[max] = msb;
		succesful = recurse(max - 1, sa, sb, moves, size);
	}
	if (!succesful)
	{
		moves[max -1] = nm;
		un_swap_np(sb);
		sswap_np(sa, sb);
		moves[max] = mss;
		succesful = recurse(max - 1, sa, sb, moves, size);
	}
	return (succesful);
}
