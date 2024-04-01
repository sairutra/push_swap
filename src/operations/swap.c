#include "../shared/push_swap.h"

int	swap_check(t_pslist** stack)
{
	int elm;
	t_pslist* head;

	head = (*stack); 
	elm = 0;
	while((*stack))
	{
		elm++;
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
	return(elm);
}

void	swap(t_pslist** stack)
{
	t_pslist* temp;
	
	if(swap_check(stack) < 2)
		return;
	temp = (*stack)->next;
	(*stack)->next = temp->next; 
	temp->next = (*stack);
	(*stack) = temp;
}

void	sswap(t_pslist** stack_a, t_pslist** stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
