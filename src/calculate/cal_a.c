#include "../../inc/push_swap.h"

void cal_a(int *a, t_pslist** stack_a, t_pslist** stack_b, int size_a)
{
	int half;
	int index;
	int b_index;
	t_pslist* temp_a;
	t_pslist* temp_b;

	half = size_a / 2;
	b_index = 0;
	index = 0;
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	while (temp_b != NULL)
	{
		while (temp_a != NULL)
		{
			if(temp_a->next == NULL)
				break;
			if (temp_b->content < temp_a->content && ps_lstlast((*stack_a))->content < temp_b->content ) // && index == 0
				break;
			if (ps_lstlast((*stack_a))->content == maxnum(stack_a) && temp_b->content > ps_lstlast((*stack_a))->content)
				break;
			if (temp_b->content < temp_a->content &&  ps_lstlast((*stack_a))->content == maxnum(stack_a) ) // && index == 0
				break;
			if (temp_a->content < temp_b->content && temp_b->content < temp_a->next->content)
			{	
				index++;
				break;
			}
			index++;
			temp_a = temp_a->next;
		}
		temp_a = (*stack_a);
		if (index > half)
			a[b_index] = index - size_a ;
		else
			a[b_index] = index;
		index = 0;
		b_index++;
		temp_b = temp_b->next;
	}
}