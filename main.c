#include "src/shared/push_swap.h"
#include <stdio.h>

t_pslist *create_stack_a_node(char *v)
{
	int		content;
	t_pslist	*node;

	content = ft_atoi(v);
	node = ps_lstnew(content);
	if (node == NULL)
		return (NULL);
	printf("create_node: %d\n", node->content);
	return(node);
}

int	create_stack_a(t_pslist **llist, char **argv)
{
	int			index;
	t_pslist	*new_node;

	index = 0;
	new_node = create_stack_a_node(argv[index++]);
	if(new_node == NULL)
		return (EXIT_FAILURE);
	ps_lstadd_back(llist, new_node);
	while(argv[index] != NULL)
	{
		new_node = create_stack_a_node(argv[index]);
		printf("test new: %d\n", new_node->content);
		if (new_node == NULL)
			return (EXIT_FAILURE);
		ps_lstadd_back(llist, new_node);
		printf("listsize: %d\n", ps_lstsize(*llist));
		index++;
	}
	return(EXIT_SUCCESS);
}

int main (int argc, char **argv)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (check_stack_a(++argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if(create_stack_a(&stack_a, argv))
		exit(EXIT_FAILURE);
	while (stack_a != NULL)
	{
		printf("test: %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ps_lstclear(&stack_a);
	return(0);
}
