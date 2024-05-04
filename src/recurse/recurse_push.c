/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:05 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 13:31:01 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse_push(int max, t_pslist **st[], t_moves **mv, int size)
{
	int	succesful;

	mv_dellast(mv);
	un_sswap_np(st[stacka], st[stackb]);
	push_np(st[stacka], st[stackb]);
	mv_lstadd_back(mv, mv_lstnew(mpb));
	succesful = recurse(max - 1, st, mv, size);
	if (!succesful)
	{
		mv_dellast(mv);
		un_push_np(st[stackb], st[stacka]);
		push_np(st[stackb], st[stacka]);
		mv_lstadd_back(mv, mv_lstnew(mpa));
		succesful = recurse(max - 1, st, mv, size);
	}
	if (!succesful)
	{
		mv_dellast(mv);
		un_push_np(st[stacka], st[stackb]);
	}
	return (succesful);
}
