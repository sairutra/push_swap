/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:05 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 19:37:30 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse_push(int max, t_pslist**sa, t_pslist **sb, int *moves, int size)
{
	int	succesful;

	moves[max -1] = nm;
	un_sswap_np(sa, sb);
	push_np(sa, sb);
	moves[max] = mpa;
	succesful = recurse(max - 1, sa, sb, moves, size);
	if (!succesful)
	{
		moves[max -1] = nm;
		if (ps_lstsize((*sa)) >= 1)
		{
			un_push_np(sb, sa);
		}
		push_np(sb, sa);
		moves[max] = mpb;
		succesful = recurse(max - 1, sa, sb, moves, size);
	}
	if (!succesful)
	{
		moves[max -1] = nm;
		if (ps_lstsize((*sb)) >= 1)
			un_push_np(sa, sb);
	}
	return (succesful);
}
