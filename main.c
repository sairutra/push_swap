#include "src/shared/push_swap.h"
#include <stdio.h>


int main (int argc, char **argv)
{
	t_pslist	*head;
	t_pslist	*headb;
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
	if(create_stack(&stack_b, argv))
		exit(EXIT_FAILURE);
	head = stack_a;
	// ps_lstdelone(stack_b->next);
	// stack_b->next = NULL;
	headb = stack_b;
	sswap(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	head = stack_a;
	headb = stack_b;
	while (stack_a != NULL)
	{
		printf("test: %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		printf("testb: %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	stack_a = head;
	stack_b = headb;
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
	return(0);
}
