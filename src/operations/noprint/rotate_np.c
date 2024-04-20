#include "../../../inc/push_swap.h"

void rotate_np(t_pslist **stack)
{
	t_pslist	*first;
	t_pslist	*second;
	t_pslist	*last;
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
	second = first->next;
	(*stack) = second;
	last->next = first;
	first->next = NULL;
}

void rrotate_np(t_pslist **stack_a, t_pslist **stack_b)
{
	rotate_np(stack_a);
	rotate_np(stack_b);
}


void un_rotate_np(t_pslist **stack)
{
	rev_rotate_np(stack);
}


void un_rrotate_np(t_pslist **stack_a, t_pslist **stack_b)
{
	rev_rrotate_np(stack_a, stack_b);
}
