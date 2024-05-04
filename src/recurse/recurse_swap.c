/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:36:14 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 13:32:02 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse_swap(int max, t_pslist **st[], t_moves **mv, int size)
{
	int	succesful;

	mv_dellast(mv);
	un_rev_rrotate_np(st[stacka], st[stackb]);
	swap_np(st[stacka]);
	mv_lstadd_back(mv, mv_lstnew(msa));
	succesful = recurse(max - 1, st, mv, size);
	if (!succesful)
	{
		mv_dellast(mv);
		un_swap_np(st[stacka]);
		swap_np(st[stackb]);
		mv_lstadd_back(mv, mv_lstnew(msb));
		succesful = recurse(max - 1, st, mv, size);
	}
	if (!succesful)
	{
		mv_dellast(mv);
		un_swap_np(st[stackb]);
		sswap_np(st[stacka], st[stackb]);
		mv_lstadd_back(mv, mv_lstnew(mss));
		succesful = recurse(max - 1, st, mv, size);
	}
	return (succesful);
}
