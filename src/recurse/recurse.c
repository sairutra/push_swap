/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:15:10 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 19:36:00 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	recurse(int max, t_pslist**sa, t_pslist **sb, int *moves, int size)
{
	int	succesful;

	succesful = 0;
	if (ps_lstsize((*sa)) == size)
	{
		if (check_n_sorted(sa, size, '+'))
			return (1);
	}
	if (max < 1)
		return (0);
	rotate_np(sa);
	moves[max] = mra;
	succesful = recurse_rotate(max - 1, sa, sb, moves, size);
	if (!succesful)
		succesful = recurse_swap(max - 1, sa, sb, moves, size);
	if (!succesful)
		succesful = recurse_push(max - 1, sa, sb, moves, size);
	return (succesful);
}
