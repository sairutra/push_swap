/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:37:14 by spenning          #+#    #+#             */
/*   Updated: 2024/04/28 18:37:28 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_moves(int*a, int*b, int size_b)
{
	int	index;

	index = 0;
	ft_printf("-------------\na		b\n");
	while (index < size_b)
	{
		ft_printf("%d		%d\n", a[index], b[index]);
		index++;
	}
}
