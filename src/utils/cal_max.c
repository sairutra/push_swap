/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:25:43 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:26:28 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	calc_max(t_pslist**stack_a)
{
	int	size;

	size = ps_lstsize((*stack_a));
	if (size <= 3)
		return (size * (3 / 3));
	if (size <= 5)
		return (size * (12 / 5));
	if (size <= 100)
		return (size * (700 / 100));
	if (size > 100)
		return (size * (5500 / 500));
	return (size);
}
