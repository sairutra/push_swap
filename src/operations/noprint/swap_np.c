#include "../../../inc/push_swap.h"


int	swap_check_np(t_pslist** stack)
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


void	swap_np(t_pslist** stack)
{
	t_pslist* temp;
	
	if(swap_check_np(stack) < 2)
		return;
	temp = (*stack)->next;
	(*stack)->next = temp->next; 
	temp->next = (*stack);
	(*stack) = temp;
}

void	sswap_np(t_pslist** stack_a, t_pslist** stack_b)
{
	swap(stack_a, ss);
	swap(stack_b, ss);
}

void	un_sswap_np(t_pslist** stack_a, t_pslist** stack_b)
{
	sswap_np(stack_a, stack_b);
}

void	un_swap_np(t_pslist** stack)
{
	t_pslist* temp;
	
	if(swap_check_np(stack) < 2)
		return;
	temp = (*stack)->next;
	(*stack)->next = temp->next; 
	temp->next = (*stack);
	(*stack) = temp;
}
