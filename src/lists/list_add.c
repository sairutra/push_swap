#include "../../inc/push_swap.h"

void	ps_lstadd_front(t_pslist	**lst, t_pslist	*new)
{
	new->next = (*lst);
	(*lst) = new;
}

void	ps_lstadd_back(t_pslist	**lst, t_pslist	*new)
{
	t_pslist	*last;

	last = ps_lstlast((*lst));
	if (last == NULL)
		(*lst) = new;
	else
		last->next = new;
}

