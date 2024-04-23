#include "../../inc/push_swap.h"


void is(int *stack_c, int *lis, int len)
{
	int index;
	int inner_index;
	int value;

	index = len;
	inner_index = index;
	while (index >= 0)
	{
		value = stack_c[index];
		while(inner_index <= len)
		{
			if(stack_c[inner_index] > value)
			{
				value = stack_c[inner_index];
				lis[index] += 1;
			}
			inner_index++;
		}
		index--;
		inner_index = index;
	}
}


void init_lis_stack(t_pslist **stack_a)
{
	t_pslist *temp;
	int	val;
	
	temp = *stack_a;
	temp->lis = 1;
	val = temp->content;
	while(temp != NULL)
	{
		if (temp->content > val)
		{
			val = temp->content;
			temp->lis = 1;
		}
		temp = temp->next;
	}
}

void init_lis(t_pslist **stack_a, int *lis, int len)
{
	int index;
	int max;
	int index_of_max;
	t_pslist *temp = (*stack_a);

	index = 0;
	(void)stack_a;
	max = lis[0];
	index_of_max = 0;
	while(index <= len)
	{
		if(lis[index] > max)
		{
			max = lis[index];
			index_of_max = index;
		}
		index++;
	}
	while (index_of_max > 0)
	{
		temp = temp->next;
		index_of_max--;
	}
	init_lis_stack(&temp);
}

void lis(t_pslist**stack_a)
{
	int *stack_c;
	int *lis;
	int len;

	len = ps_lstsize((*stack_a)) - 1;
	lis = malloc(sizeof(int) * len);
	if (lis == NULL)
		exit(EXIT_FAILURE);
	stack_c = malloc(sizeof(int) * ps_lstsize((*stack_a)));
	init_c(stack_a, stack_c);
	is(stack_c, lis, len);
	free(stack_c);
	init_lis(stack_a, lis, len);
	free(lis);
}

int push_b_lis(t_pslist **stack_a, t_pslist **stack_b, int n)
{
	int index;
	int moves;

	moves = 0;
	index = 0;
	while(index < n)
	{
		if((*stack_a)->lis == 0)
		{
			push(stack_a, stack_b, pa);
			moves++;
		}
		else
		{
			rotate(stack_a, ra);
			moves++;
		}
			index++;
	}
	return(moves);
}



void cal_a(int *a, t_pslist** stack_a, t_pslist** stack_b, int size_a)
{
	int half;
	int index;
	int b_index;
	t_pslist* temp_a;
	t_pslist* temp_b;

	half = size_a / 2;
	// ft_printf("half: %d\n", half);
	b_index = 0;
	index = 0;
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	while (temp_b != NULL)
	{
		// ft_printf("b_index: %d\n", b_index);
		while (temp_a != NULL)
		{
			// ft_printf("index: %d\n", index);
			// ft_printf("temp_a->content %d\n", temp_a->content);
			// ft_printf("temp_b->content %d\n", temp_b->content);
			if(temp_a->next == NULL)
				break;
			// if(temp_a->next != NULL)
				// ft_printf("temp_a->next->content %d\n", temp_a->next->content);
			if (temp_b->content < temp_a->content && index == 0)
			{
				index = 0;
				break;
			}
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

int max (int a, int b)
{
	if(a > b)
		return(a);
	return(b);
}

int min (int a, int b)
{
	if (a < b)
		return(a);
	return(b);
}

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
	print_moves(a, b, size_b);
	if (move_cost == NULL)
		exit(EXIT_FAILURE);
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
	// for (int i = 0; i < size_b; i++)
	// {
	// 	ft_printf("move_cost: %d\n", move_cost[i]);
	// }
	move_index = best_move_index(move_cost, size_b);
	free(move_cost); 
	return (move_index);
}

void execute_move(t_pslist **stack_a, t_pslist **stack_b, int *a, int *b, int move_index)
{
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
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
		rev_rotate(stack_a, rrb);
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

void	cal_moves(t_pslist **stack_a, t_pslist **stack_b)
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
		exit(EXIT_FAILURE);
	cal_a(a, stack_a, stack_b, size_a);
	cal_b(b, stack_b, size_b);
	move_index = cal_best_move_index(a, b, size_b);
	execute_move(stack_a, stack_b, a, b, move_index);
	free(a);
	free(b);
}

void recurse_cal_sort(t_pslist **stack_a, t_pslist **stack_b)
{
	int max;
	int len;

	ft_printf("start\n----------\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("----------\n");

	len = ps_lstsize((*stack_a));
	sort_index(stack_a);
	max = calc_max(stack_a);
	ft_printf("max: %d\n", max);

	lis(stack_a);
	max -= push_b_lis(stack_a, stack_b, ps_lstsize((*stack_a)));
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	while (!check_n_sorted(stack_a, len, '+'))
		cal_moves(stack_a, stack_b);
	

	ft_printf("max: %d\n", max);
	ft_printf("end\n----------\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("----------\n");
}


