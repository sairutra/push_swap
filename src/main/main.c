/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:15:31 by spenning          #+#    #+#             */
/*   Updated: 2024/04/25 16:45:07 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int main (int argc, char **argv)
{
	// t_pslist	*head;
	// t_pslist	*headb;
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	// (void)argv;
	(void)argc;
	argv = char_array_of_int(100, 0, 100);
	// if (argc == 1)
	// 	exit(EXIT_SUCCESS);
	if (check_stack(argv))
	// if (check_stack(++argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if(create_stack(&stack_a, argv))
		exit(EXIT_FAILURE);
	// bubble_sort(&stack_a, &stack_b);
	
	if(cal_sort(&stack_a, &stack_b))
		ft_printf("malloc failed in cal_sort.cal_moves");
	print_stack(&stack_a, 'a');
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
	free_char_array(argv, 10);
	return(0);
}
