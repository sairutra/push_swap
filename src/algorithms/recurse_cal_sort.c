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

// int recurse(int max, t_pslist**stack_a, t_pslist **stack_b, int *moves, int size)
// {
// 	int succesful;
// 	succesful = 0;
// 	if(ps_lstsize((*stack_a)) == size)
// 	{
// 		if(check_n_sorted(stack_a, size, '+'))
// 			return(1);
// 	}
// 	if(max < 1)
// 		return(0);
// 	rotate_np(stack_a);
// 	moves[max] = mra;
// 	succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_rotate_np(stack_a);
// 		rotate_np(stack_b);
// 		moves[max] = mrb;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_rotate_np(stack_b);
// 		rrotate_np(stack_a, stack_b);
// 		moves[max] = mrr;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_rrotate_np(stack_a, stack_b);
// 		rev_rotate_np(stack_a);
// 		moves[max] = mrra;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_rev_rotate_np(stack_a);
// 		rev_rotate_np(stack_b);
// 		moves[max] = mrrb;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_rev_rotate_np(stack_b);
// 		rev_rrotate_np(stack_a, stack_b);
// 		moves[max] = mrrr;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_rev_rrotate_np(stack_a, stack_b);
// 		swap_np(stack_a);
// 		moves[max] = msa;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_swap_np(stack_a);
// 		swap_np(stack_b);
// 		moves[max] = msb;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_swap_np(stack_b);
// 		sswap_np(stack_a, stack_b);
// 		moves[max] = mss;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		un_sswap_np(stack_a, stack_b);
// 		push_np(stack_a, stack_b);
// 		moves[max] = mpa;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		if(ps_lstsize((*stack_a)) >= 1)
// 		{
// 			un_push_np(stack_b, stack_a);
// 		}
// 		push_np(stack_b, stack_a);
// 		moves[max] = mpb;
// 		succesful = recurse(max - 1, stack_a, stack_b, moves, size);
// 	}
// 	if(!succesful)
// 	{
// 		moves[max -1] = nm;
// 		if(ps_lstsize((*stack_b)) >= 1)
// 			un_push_np(stack_a, stack_b);
// 	}
// 	return(succesful);
// }


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



void cal_a(int *a, t_pslist** stack_a, t_pslist** stack_b, int size_a, int size_b)
{
	int half;
	int index;
	int b_index;
	t_pslist* temp_a;
	t_pslist* temp_b;

	half = size_a / 2;
	ft_printf("half: %d\n", half);
	b_index = 0;
	index = 0;
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	while (temp_b != NULL)
	{
		ft_printf("b_index: %d\n", b_index);
		while (temp_a != NULL)
		{
			ft_printf("index: %d\n", index);
			ft_printf("temp_a->content %d\n", temp_a->content);
			ft_printf("temp_b->content %d\n", temp_b->content);
			if(temp_a->next != NULL)
				ft_printf("temp_a->next->content %d\n", temp_a->next->content);
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
	ft_printf("a\n--------------\n"); 
	for (int i = 0; i < size_b; i++)
	{
		ft_printf("%d\n", a[i]); 
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

void print_moves(int*a, int*b, int size_b)
{
	int index;
	
	index = 0;
	ft_printf("a		b\n");
	while(index < size_b)
	{
		ft_printf("%d		%d\n", a[index], b[index]);
		index++;
	}
}


void	cal_best_move(int*a, int*b, int size_b)
{
	// int index;

	// index = 0;
	// while (index)
	print_moves(a, b, size_b);

}

void	cal_moves(t_pslist **stack_a, t_pslist **stack_b)
{
	int *a;
	int *b;
	int size_a;
	int size_b;

	size_a = ps_lstsize((*stack_a));
	size_b = ps_lstsize((*stack_b));
	a = malloc(sizeof(int) * size_b);
	b = malloc(sizeof(int) * size_b);
	if (a == NULL || b == NULL)
		exit(EXIT_FAILURE);
	cal_a(a, stack_a, stack_b, size_a, size_b);
	cal_b(b, stack_b, size_b);
	cal_best_move(a, b, size_b);
}

void recurse_cal_sort(t_pslist **stack_a, t_pslist **stack_b)
{
	int max;

	ft_printf("start\n----------\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("----------\n");


	sort_index(stack_a);
	max = calc_max(stack_a);
	ft_printf("max: %d\n", max);

	lis(stack_a);
	max -= push_b_lis(stack_a, stack_b, ps_lstsize((*stack_a)));
	cal_moves(stack_a, stack_b);



	ft_printf("max: %d\n", max);
	ft_printf("end\n----------\n");
	print_index_lis_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	ft_printf("----------\n");
}


