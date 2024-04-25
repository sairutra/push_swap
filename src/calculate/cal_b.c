#include "../../inc/push_swap.h"


void cal_b(int *b, t_pslist** stack_b, int size_b)
{
	int half;
	int index;
	t_pslist* temp;

	index = 0;
	temp = (*stack_b);
	half = size_b / 2;
	while (temp != NULL)
	{
		if (index > half)
			b[index] = index - size_b;
		else
			b[index] = index;
		index++;
		temp = temp->next;
	}
}
