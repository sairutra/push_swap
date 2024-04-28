/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:30:55 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:31:13 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	maxnum(t_pslist **stack_a)
{
	t_pslist	*temp;
	int			max;

	temp = (*stack_a);
	max = temp->content;
	while (temp != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}
