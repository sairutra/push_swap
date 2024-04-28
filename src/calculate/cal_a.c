/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:45:13 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 19:58:18 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_ta(t_pslist *ta, t_pslist *tb, t_pslist *last, t_pslist	**sa)
{
	int	index;

	index = 0;
	while (ta != NULL)
	{
		if (ta->next == NULL)
			break ;
		if (tb->content < ta->content && last->content < tb->content)
			break ;
		if (last->content == maxnum(sa) && tb->content > last->content)
			break ;
		if (tb->content < ta->content && last->content == maxnum(sa))
			break ;
		if (last->content < tb->content && tb->content < ta->content)
			break ;
		index++;
		ta = ta->next;
	}
	return (index);
}

void	cal_a(int *a, t_pslist	**sa, t_pslist	**sb, int size_a)
{
	int			half;
	int			index;
	int			b_index;
	t_pslist	*ta;
	t_pslist	*tb;

	half = size_a / 2;
	b_index = 0;
	index = 0;
	ta = (*sa);
	tb = (*sb);
	while (tb != NULL)
	{
		index = check_ta(ta, tb, ps_lstlast((*sa)), sa);
		ta = (*sa);
		if (index > half)
			a[b_index] = index - size_a ;
		else
			a[b_index] = index;
		index = 0;
		b_index++;
		tb = tb->next;
	}
}
