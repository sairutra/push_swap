#include "../../inc/push_swap.h"
#include <stdio.h>
#include "../../gnirut.h"

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
	argv = char_array_of_int(20, 0, 20);
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
	recurse_cal_sort(&stack_a, &stack_b);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
	return(0);
}
