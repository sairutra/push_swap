/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:15:10 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 16:07:00 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse(int max, t_pslist **st[], t_moves **mv, int size)
{
	int	succesful;

	succesful = 0;
	if (ps_lstsize((*st[stacka])) == size)
	{
		if (check_n_sorted(st[stacka], size, '+'))
			return (1);
	}
	if (max < 1)
		return (0);
	rotate_np(st[stacka]);
	mv_lstadd_back(mv, mv_lstnew(mra));
	succesful = recurse(max - 1, st, mv, size);
	if (!succesful)
		succesful = recurse_rotate(max - 1, st, mv, size);
	if (!succesful)
		succesful = recurse_swap(max - 1, st, mv, size);
	if (!succesful)
	{
		mv_dellast(mv);
		un_sswap_np(st[stacka], st[stackb]);
	}
	return (succesful);
}
