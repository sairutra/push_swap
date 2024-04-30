/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:27:39 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:32:48 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_push(t_moves *temp)
{
	if (temp->move == mpa)
		ft_printf("pa\n");
	if (temp->move == mpb)
		ft_printf("pb\n");
}

void	print_t_moves(t_moves **moves)
{
	t_moves	*temp;

	temp = (*moves);
	while (temp != NULL)
	{
		print_push(temp);
		if (temp->move == mra)
			ft_printf("ra\n");
		if (temp->move == mrb)
			ft_printf("rb\n");
		if (temp->move == mrr)
			ft_printf("rr\n");
		if (temp->move == mrra)
			ft_printf("rra\n");
		if (temp->move == mrrr)
			ft_printf("rrr\n");
		if (temp->move == msa)
			ft_printf("sa\n");
		if (temp->move == msb)
			ft_printf("sb\n");
		if (temp->move == mss)
			ft_printf("ss\n");
		temp = temp->next;
	}
}
