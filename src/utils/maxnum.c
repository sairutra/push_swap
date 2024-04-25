#include "../../inc/push_swap.h"

int maxnum(t_pslist **stack_a)
{
	t_pslist	*temp;
	int			max;

	temp = (*stack_a);
	max = temp->content;
	while (temp != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return(max);
}
