#include "src/shared/push_swap.h"

t_list *create_stack_a(char **argv)
{
	int		index;
	int		*content;
	t_list	*llist;
	t_list	*new_node;

	index = 1;

	llist = ft_lstnew(argv[0]);
	if (llist == NULL)
		return (NULL);
	while(argv[index] != NULL)
	{
		content = malloc(sizeof(int));
		if(content == NULL)
			return (NULL);
		content = ft_atoi(argv[index]); 
		new_node = ft_lstnew(content);
		if (new_node == NULL)
			return (NULL);
		ft_lstadd_back(&llist, new_node);
		index++;
	}
	return(llist);
}

int main (int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (check_stack_a(++argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = create_stack_a(argv);
	(void)stack_b;
	ft_printf("Stack a\n");
	while(stack_a->next != NULL)
	{
		ft_printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return(0);
}
