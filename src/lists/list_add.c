/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:23 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 17:37:13 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ps_lstadd_front(t_pslist	**lst, t_pslist	*new)
{
	new->next = (*lst);
	(*lst) = new;
}

void	ps_lstadd_back(t_pslist	**lst, t_pslist	*new)
{
	t_pslist	*last;

	last = ps_lstlast((*lst));
	if (last == NULL)
		(*lst) = new;
	else
		last->next = new;
}

void	mv_lstadd_front(t_moves	**lst, t_moves	*new)
{
	new->next = (*lst);
	(*lst) = new;
}

void	mv_lstadd_back(t_moves	**lst, t_moves	*new)
{
	t_moves	*last;

	last = mv_lstlast((*lst));
	if (last == NULL)
		(*lst) = new;
	else
		last->next = new;
}
