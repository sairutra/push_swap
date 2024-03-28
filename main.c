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

t_pslist *create_stack_a(char **argv)
{
	int		index;
	t_pslist	*llist;
	t_pslist	*new_node;

	index = 0;
	new_node = create_stack_a_node(argv[index++]);
	if(new_node == NULL)
		return (NULL);
	llist = new_node;
	while(argv[index] != NULL)
	{
		new_node = create_stack_a_node(argv[index]);
		if (new_node == NULL)
			return (NULL);
		ps_lstadd_back(&llist, new_node);
		index++;
	}
	return(llist);
}

int main (int argc, char **argv)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (check_stack_a(++argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = create_stack_a(argv);
	if(stack_a == NULL)
		exit(EXIT_FAILURE);
	(void)stack_b;
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return(0);
}
