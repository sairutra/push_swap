#include "../../inc/push_swap.h"

void rotate_print(int print)
{
	if(print == ra)
		ft_printf("ra\n");
	if(print == rb)
		ft_printf("rb\n");	
}


void rotate(t_pslist **stack, int print)
{
	t_pslist	*first;
	t_pslist	*second;
	t_pslist	*last;
	// t_pslist	*second_last;
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
		rotate_print(print);
		return;
	}
	// second_last = ps_lst_second_last((*stack));
	second = first->next;
	(*stack) = second;
	last->next = first;
	// second_last->next = first;
	first->next = NULL;
	rotate_print(print);
}

void rrotate(t_pslist **stack_a, t_pslist **stack_b)
{
	ft_printf("rr\n");
	rotate(stack_a, rr);
	rotate(stack_b, rr);
}
