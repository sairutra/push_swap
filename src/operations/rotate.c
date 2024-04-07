#include "../../inc/push_swap.h"

void rotate(t_pslist **stack, int print)
{
	t_pslist	*first;
	t_pslist	*last;
	t_pslist	*second_last;
	int			lstsize;

	first = (*stack);
	last = ps_lstlast((*stack));
	lstsize = ps_lstsize((*stack));
	if (lstsize <= 1)
		return;
	if (lstsize == 2)
	{
		(*stack) = last;
		last->next = first;
		(*stack)->next->next = NULL;
		return;
	}
	second_last = ps_lst_second_last((*stack));
	(*stack) = last;
	last->next = first->next;
	second_last->next = first;
	first->next = NULL;
	if(print == ra)
		ft_printf("ra\n", last->content);
	if(print == rb)
		ft_printf("rb\n", last->content);
}

