#include "../../inc/push_swap.h"

int check_array(int *array)
{
    int index;

    index = 0;
    while (index < 10)
    {
        if(array[index] != 0)
            return(0);
        index++;
    }
    return(1);
}

void count_ranking(int *array, t_pslist	**stack)
{
    t_pslist* temp;

    ft_memset(array, 0, sizeof(int) * 10);
    temp = (*stack);
    while(temp != NULL)
    {
        array[temp->rrank] += 1;
        temp = temp->next;
    }
}

int recurse_rank(int content, int depth, int base)
{
    depth = depth - 1;
    if (depth == 0)
        return(content % base);
    return(recurse_rank(content/10, depth, base));
}


void give_ranking(t_pslist	**stack, int depth, int base)
{
    t_pslist *temp;

    temp = (*stack);
    while(temp != NULL)
    {
        temp->rrank = recurse_rank(temp->content, depth, base);
        temp = temp->next;
    }
}


void radix(t_pslist	**stack_a, t_pslist	**stack_b)
{
    int len;
    int d;
    int digit_index;
    int count[10];
    int count_index;

    len = ps_lstsize((*stack_a));
    d = ndigits((*stack_a));
    digit_index = 1;
    count_index = 0;

    (void)len;
    ft_printf("digits: %d\n", d);
    while(digit_index <= d)
    {
        give_ranking(stack_a, digit_index, 10);
        count_ranking(count, stack_a);
        print_rank_stack(stack_a, 'a');
        for (size_t i = 0; i < 10; i++)
            ft_printf("[%d]count: %d\n",i, count[i]);
        while(!check_array(count) && count_index < 10)
        {
            if(count[count_index] == 0)
                count_index++;
            ft_printf("count_index %d\n", count_index);
            if((*stack_a)->rrank == count_index)
            {
                push(stack_a, stack_b, pa);
                print_rank_stack(stack_a, 'a');
                print_stack(stack_b, 'b');
                count[count_index] -= 1;
            }
            else
            {
                print_rank_stack(stack_a, 'a');
                print_stack(stack_b, 'b');
                rotate(stack_a, ra);
            }
        }
        while ((*stack_b) != NULL)
				push(stack_b, stack_a, pb);
        count_index = 0;
        digit_index++;
    }
    //  while d > 0 
    //      stack_a.m->rank =  recurs_digit(d, content)

}
