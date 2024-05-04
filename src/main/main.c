/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:15:31 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 17:53:42 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


void free_all(char **argv, t_pslist	*stack_a, t_pslist	*stack_b)
{
	free_char_array(argv);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	argv = init_argv(++argv, argc);
	if (argv == NULL)
		exit(EXIT_FAILURE);
	if (check_stack(argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (create_stack(&stack_a, argv))
		exit(EXIT_FAILURE);
	sort_index(&stack_a);
	add_binary(&stack_a);
	if (ps_lstsize(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
		radix(&stack_a, &stack_b);
	free_all(argv, stack_a, stack_b);
	return (0);
}
