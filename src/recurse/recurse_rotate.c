/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:36:35 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 13:31:44 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recu_rev_rotate(int max, t_pslist **st[], t_moves **mv, int size)
{
	int	succesful;

	mv_dellast(mv);
	un_rrotate_np(st[stacka], st[stackb]);
	rev_rotate_np(st[stacka]);
	mv_lstadd_back(mv, mv_lstnew(mrra));
	succesful = recurse(max - 1, st, mv, size);
	if (!succesful)
	{
		mv_dellast(mv);
		un_rev_rotate_np(st[stacka]);
		rev_rotate_np(st[stackb]);
		mv_lstadd_back(mv, mv_lstnew(mrrb));
		succesful = recurse(max - 1, st, mv, size);
	}
	if (!succesful)
	{
		mv_dellast(mv);
		un_rev_rotate_np(st[stackb]);
		rev_rrotate_np(st[stacka], st[stackb]);
		mv_lstadd_back(mv, mv_lstnew(mrrr));
		succesful = recurse(max - 1, st, mv, size);
	}
	return (succesful);
}

int	recurse_rotate(int max, t_pslist **st[], t_moves **mv, int size)
{
	int	succesful;

	mv_dellast(mv);
	un_rotate_np(st[stacka]);
	rotate_np(st[stackb]);
	mv_lstadd_back(mv, mv_lstnew(mrb));
	succesful = recurse(max - 1, st, mv, size);
	if (!succesful)
	{
		mv_dellast(mv);
		un_rotate_np(st[stackb]);
		rrotate_np(st[stacka], st[stackb]);
		mv_lstadd_back(mv, mv_lstnew(mrr));
		succesful = recurse(max - 1, st, mv, size);
	}
	if (!succesful)
		succesful = recu_rev_rotate(max - 1, st, mv, size);
	return (succesful);
}
