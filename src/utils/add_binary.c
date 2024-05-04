/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:35:46 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 17:03:02 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result = result * base;
		exponent--;
	}
	return (result);
}

void	add_binary(t_pslist	**stack_a)
{
	int			index;
	int			value;
	t_pslist	*temp;

	value = 0;
	index = 0;
	temp = (*stack_a);
	while (temp != NULL)
	{
		while (index <= 32)
		{
			value = ((temp->index >> index) & 1) * power(10, index);
			temp->binary += value;
			index++;
		}
		index = 0;
		temp = temp->next;
	}
}
