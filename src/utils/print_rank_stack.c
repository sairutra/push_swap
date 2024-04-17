#include "../../inc/push_swap.h"

void print_rank_stack(t_pslist	**stack, char name)
{
	t_pslist	*temp;

	temp = (*stack);
	ft_printf("stack: %c \n", name);
	while (temp != NULL)
	{
		ft_printf("content:%d ranking:%d \n", temp->content, temp->rrank);
		temp = temp->next;
	}
	ft_printf("\n");
}

