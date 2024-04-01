#include "src/shared/push_swap.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	t_pslist	*head;
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
	if(create_stack(&stack_a, argv))
		exit(EXIT_FAILURE);
	head = stack_a;
	while (stack_a != NULL)
	{
		printf("test: %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	stack_a = head;
	ps_lstclear(&stack_a);
	return(0);
}
