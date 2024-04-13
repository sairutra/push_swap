#include "../../inc/push_swap.h"

int check_n_sorted(t_pslist	**stack_a, int n,const char flag)
{
	int			sorted;
	t_pslist	*temp;
	int			index;

	index = 1;
	sorted = 1;
	temp = (*stack_a);
	while (temp->next != NULL && index < n)
	{
		if((temp->content >= temp->next->content) && (flag == '+'))
			sorted = 0;
		if((temp->content <= temp->next->content) && (flag == '-'))
			sorted = 0;
		temp = temp->next;
		index++;
	}
	if (index != n)
		sorted = 0;
	return(sorted);
}
