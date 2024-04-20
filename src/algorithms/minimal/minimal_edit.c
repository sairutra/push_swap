#include "../../../inc/push_swap.h"


void ss_swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
  
        ss_swap(&arr[min_idx], &arr[i]); 
    } 
} 


void init_c(t_pslist **stack_a, int *stack_c)
{
	t_pslist *temp;
	int      index;

	index = 0;
	temp = (*stack_a);
	while (temp != NULL)
	{
		stack_c[index] = temp->content;
		temp = temp->next;
		index++;
	}
	index = 0;
}

void init_index(t_pslist **stack_a, int *stack_c, int len)
{
	t_pslist *temp;
	int      index;

	index = 0;
	while(index < len)
	{
		temp = (*stack_a);
		while (temp != NULL)
		{
			if (stack_c[index] == temp->content)
			{
				temp->index = index;
				break;
			}
			else
				temp = temp->next;
		}
		index++;
	}
}

void sort(t_pslist **stack_a)
{
	int *stack_c;
	int len;

	len = ps_lstsize((*stack_a));
	stack_c = malloc(sizeof(int) * len);
	if (stack_c == NULL)
		exit(EXIT_FAILURE);
	init_c(stack_a, stack_c);
	selectionSort(stack_c, len);
	init_index(stack_a, stack_c, len);
	for (int i = 0; i < len; i++)
	{
		ft_printf("stack c: %d\n", stack_c[i]);
	}
	print_index_stack(stack_a, 'a');
	
}


void minimal_edit(t_pslist **stack_a, t_pslist **stack_b)
{
	sort(stack_a);
	(void)stack_b;
}
