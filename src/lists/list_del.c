/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:10:26 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:11:01 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ps_lstdelone(t_pslist	*lst)
{
	lst->content = 0;
	free(lst);
}

void	ps_lstclear(t_pslist	**lst)
{
	t_pslist	*temp_frt;
	t_pslist	*temp_bck;

	if (!lst)
		return ;
	temp_frt = (*lst);
	temp_bck = (*lst);
	while (temp_bck)
	{
		temp_frt = temp_frt->next;
		temp_bck->content = 0;
		free(temp_bck);
		temp_bck = temp_frt;
	}
	(*lst) = 0;
}
