/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:15:31 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 13:05:26 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (check_stack(++argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (create_stack(&stack_a, argv))
		exit(EXIT_FAILURE);
	if (ps_lstsize(stack_a) < 6)
		recurse_sort(&stack_a, &stack_b);
	else
		radix(&stack_a, &stack_b);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
	return (0);
}
