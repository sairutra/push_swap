/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:15:43 by spenning          #+#    #+#             */
/*   Updated: 2024/04/25 17:00:53 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	execute_move_an_bp(t_pslist **sa, t_pslist **sb, int a, int b)
{
	if ((a * -1) > b)
		rev_rotate(sa, rra);
	else
		rev_rotate(sb, rrb);
}

void	execute_move_ap_bn(t_pslist **sa, t_pslist **sb, int a, int b)
{
	if (a > (b) * -1)
		rev_rotate(sb, rrb);
	else
		rev_rotate(sa, rra);
}

void	execute_move(t_pslist **sa, t_pslist **sb, int a, int b)
{
	ft_printf("a: %d", a);
	ft_printf("b: %d", b);
	if (a == 0 && b == 0)
		push(sb, sa, pa);
	if (a == 0 && b == 0 && (*sb) == NULL)
		rotate(sa, ra);
	if (a > 0 && b > 0)
		rrotate(sa, sb);
	if (a > 0 && b == 0)
		rotate(sa, ra);
	if (a == 0 && b > 0)
		rotate(sb, rb);
	if (a < 0 && b < 0)
		rev_rrotate(sa, sb);
	if (a < 0 && b == 0)
		rev_rotate(sa, rra);
	if (a == 0 && b < 0)
		rev_rotate(sb, rrb);
	if (a < 0 && b > 0)
		execute_move_an_bp(sa, sb, a, b);
	if (a > 0 && b < 0)
		execute_move_ap_bn(sa, sb, a, b);
}
