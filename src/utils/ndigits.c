/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ndigits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:32:05 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:33:04 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_digits(int value)
{
	int	ret;

	value = value / 10;
	ret = 1;
	if (value > 0)
		ret += get_digits(value);
	return (ret);
}

int	ndigits(t_pslist *stack)
{
	int			max_digits;
	int			digits;
	t_pslist	*temp;

	max_digits = 0;
	digits = 0;
	temp = stack;
	while (temp != NULL)
	{
		digits = get_digits(temp->content);
		if (digits > max_digits)
			max_digits = digits;
		temp = temp->next;
	}
	return (max_digits);
}
