#include "../../inc/push_swap.h"

int check_n_sorted(t_pslist	**stack_a, int n,const char flag)
{
	int			sorted;
	t_pslist	*temp;
	int			index;

	index = 1;
	sorted = 1;
	temp = (*stack_a);
	// print_stack(stack_a, 'a');
	// ft_printf("check index: %d\n", index);
	// ft_printf("temp: %d\n", temp->content);
	// ft_printf("n: %d\n", n);
	// ft_printf("temp->next: %d\n", temp->next->content);
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


int check_sorted_stack(t_pslist	**stack_a, t_pslist**stack_b)
{
	t_pslist	*temp;

	temp = (*stack_a);
	if((*stack_b) == NULL)
		return(0);
	while (temp != NULL)
	{
		if(temp-> content < (*stack_b)->content)
			return(0);
		temp = temp->next;
	}
	if(check_n_sorted(stack_a, ps_lstsize((*stack_a)), '+') && check_n_sorted(stack_b, ps_lstsize((*stack_b)), '-'))
		return(1);
	return(0);
}