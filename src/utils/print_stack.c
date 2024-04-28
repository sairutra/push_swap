/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:37:57 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:38:13 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_stack(t_pslist	**stack, char name)
{
	t_pslist	*temp;

	temp = (*stack);
	ft_printf("stack: %c ", name);
	while (temp != NULL)
	{
		ft_printf("%d ", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}
