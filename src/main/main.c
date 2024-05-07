/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:15:31 by spenning      #+#    #+#                 */
/*   Updated: 2024/05/07 18:00:46 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_all(char **argv, t_pslist	*stack_a, t_pslist	*stack_b)
{
	free_char_array(argv);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
}

void	check_args(char **argv)
{
	if (argv[0] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
	if (check_stack(argv))
	{
		free_char_array(argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
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
	check_args(argv);
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
