#include "../../inc/push_swap.h"

int	ps_lstsize(t_pslist *lst)
{
	int		size;
	t_pslist	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

