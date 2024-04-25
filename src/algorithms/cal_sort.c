#include "../../inc/push_swap.h"

int	best_move_index(int *move_cost, int size_b)
{
	int index;
	int value;
	int ret_index;

	index = 0;
	value = move_cost[index];
	ret_index = 0;
	while(index < size_b)
	{
		if (move_cost[index] < value)
		{
			value = move_cost[index];
			ret_index = index;
		}
		index++;
	}
	return(ret_index);
}

int	cal_best_move_index(int*a, int*b, int size_b)
{
	int index;
	int *move_cost;
	int move_index;

	index = 0;
	move_cost = malloc(sizeof(int) * size_b);
	if (move_cost == NULL)
		return(-1);
	while (index < size_b)
	{
		if (a[index] >= 0 && b[index] >= 0)
			move_cost[index] = max(a[index], b[index]);
		if (a[index] < 0 && b[index] >= 0)
			move_cost[index] = (a[index] * -1) + b[index];
		if (a[index] >= 0 && b[index] < 0)
			move_cost[index] =  a[index] + (b[index] * -1);
		if (a[index] < 0 && b[index] < 0)
			move_cost[index] =  min(a[index], b[index]) * -1;
		index++;
	}
	move_index = best_move_index(move_cost, size_b);
	free(move_cost); 
	return (move_index);
}

void execute_move(t_pslist **stack_a, t_pslist **stack_b, int *a, int *b, int move_index)
{
	if(a[move_index] == 0 && b[move_index] == 0)
		push(stack_b, stack_a, pa);
	if(a[move_index] > 0 && b[move_index] > 0)
		rrotate(stack_a, stack_b);
	if(a[move_index] > 0 && b[move_index] == 0)
		rotate(stack_a, ra);
	if(a[move_index] == 0 && b[move_index] > 0)
		rotate(stack_b, rb);
	if(a[move_index] < 0 && b[move_index] < 0)
		rev_rrotate(stack_a, stack_b);
	if(a[move_index] < 0 && b[move_index] == 0)
		rev_rotate(stack_a, rra);
	if(a[move_index] == 0 && b[move_index] < 0)
		rev_rotate(stack_b, rrb);
	if(a[move_index] < 0 && b[move_index] > 0)
	{
		if ((a[move_index] * -1) > b[move_index])
			rev_rotate(stack_a, rra);
		else
			rev_rotate(stack_b, rrb);
	}
	if(a[move_index] > 0 && b[move_index] < 0)
	{
		if (a[move_index] > (b[move_index]) * -1)
			rev_rotate(stack_b, rrb);
		else
			rev_rotate(stack_a, rra);
	}
}

int	cal_moves(t_pslist **stack_a, t_pslist **stack_b)
{
	int *a;
	int *b;
	int size_a;
	int size_b;
	int move_index;

	size_a = ps_lstsize((*stack_a));
	size_b = ps_lstsize((*stack_b));
	a = malloc(sizeof(int) * size_b);
	b = malloc(sizeof(int) * size_b);
	if (a == NULL || b == NULL)
		return(-1);
	cal_a(a, stack_a, stack_b, size_a);
	cal_b(b, stack_b, size_b);
	move_index = cal_best_move_index(a, b, size_b);
	if(move_index == -1)
	{
		free(a);
		free(b);
		return(-1);
	}
	execute_move(stack_a, stack_b, a, b, move_index);
	free(a);
	free(b);
	return(0);
}

int cal_sort(t_pslist **stack_a, t_pslist **stack_b)
{
	int len;
	int ret;

	len = ps_lstsize((*stack_a));
	lis(stack_a);
	ret = 0;
	push_b_lis(stack_a, stack_b, ps_lstsize((*stack_a)));
	while (!check_n_sorted(stack_a, len, '+'))
	{	
		ret = cal_moves(stack_a, stack_b);
		if (ret == -1)
			return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}


