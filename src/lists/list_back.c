/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:09:29 by spenning          #+#    #+#             */
/*   Updated: 2024/04/30 16:03:26 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_pslist	*ps_lst_second_last(t_pslist	*lst)
{
	t_pslist	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	if (last->next->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}

t_pslist	*ps_lstlast(t_pslist	*lst)
{
	t_pslist	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
		{
			last = last->next;
			return (last);
		}
		last = last->next;
	}
	return (last);
}

t_moves	*mv_lst_second_last(t_moves	*lst)
{
	t_moves	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	if (last->next->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}

t_moves	*mv_lstlast(t_moves	*lst)
{
	t_moves	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
		{
			last = last->next;
			return (last);
		}
		last = last->next;
	}
	return (last);
}
