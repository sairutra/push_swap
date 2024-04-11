#include "../../inc/push_swap.h"

void bubble_sort(t_pslist	**stack_a, t_pslist	**stack_b)
{
	int	len;

	push(stack_a, stack_b, pa);
	len = ps_lstsize((*stack_a));
	while (!check_n_sorted(stack_a, len, '-'))
	{
		if((*stack_a)-> content > (*stack_b)->content || (*stack_b) == NULL)
		{
			push(stack_a, stack_b, pa);
			print_stack(stack_a, 'a');
			print_stack(stack_b, 'b');
		}
		if((*stack_a)-> content < (*stack_b)->content)
		{
			push(stack_b, stack_a, pb);
			print_stack(stack_a, 'a');
			print_stack(stack_b, 'b');
			swap(stack_a, sa);
			print_stack(stack_a, 'a');
			print_stack(stack_b, 'b');
		}
		//check is sorted a && is sorted b 
		// then push b on a
	}
}
