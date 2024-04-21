#include "../../inc/push_swap.h"

int get_max_index(t_pslist **stack_a)
{
    int max;
    t_pslist *temp;

    temp = (*stack_a);
    max = temp->index;
    while (temp != NULL)
    {
        if (temp->index > max)
            max = temp->index;
        temp = temp->next;
    }
    temp = (*stack_a);
    while (temp != NULL)
    {
        if (temp->index == max)
            temp->lds = 1;
        temp = temp->next;
    }
    return(max);
}

void ds(t_pslist **stack_a, int max, int n)
{
    t_pslist *temp;
    int index;
    
    if (n <= 0)
        return;
    temp = (*stack_a);
    index = 0;
    while(temp->index != max && index < n && temp != NULL)
    {
        if(temp ->index == max - 1)
            temp->lds = 1;
        index++;
        temp = temp->next;
    }
    ds(stack_a, max - 1, index -1);
    return;
}

void lds(t_pslist**stack_a)
{
    int max;

    max = get_max_index(stack_a);
    ds(stack_a, max, ps_lstsize((*stack_a)));   
    print_index_lds_stack(stack_a, 'a');
 
}

int recurse(int max, t_pslist**stack_a, t_pslist **stack_b, int *moves, int size)
{
    int succesful;

    // for (int i = size; i > 0; i--)
    // {
    //     if(moves[i] == mpa)
    //         ft_printf("pa\n");
    //     if(moves[i] == mpb)
    //         ft_printf("pb\n");
    //     if(moves[i] == mra)
    //         ft_printf("ra\n");
    //     if(moves[i] == mrb)
    //         ft_printf("rb\n");
    //     if(moves[i] == mrr)
    //         ft_printf("rr\n");
    //     if(moves[i] == mrra)
    //         ft_printf("rra\n");
    //     if(moves[i] == mrrr)
    //         ft_printf("rrr\n");
    //     if(moves[i] == msa)
    //         ft_printf("sa\n");
    //     if(moves[i] == msb)
    //         ft_printf("sb\n");
    //     if(moves[i] == mss)
    //         ft_printf("ss\n");
    // }
    // print_stack(stack_a, 'a');
    // print_stack(stack_b, 'b');
    succesful = 0;
    if(ps_lstsize((*stack_a)) == size)
    {
        if(check_n_sorted(stack_a, size, '+'))
            return(1);
    }
    if(max < 1)
        return(0);
    rotate_np(stack_a);
    moves[max] = mra;
    succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    if(!succesful)
    {
        moves[max -1] = nm;
        un_rotate_np(stack_a);
        rotate_np(stack_b);
        moves[max] = mrb;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_rotate_np(stack_b);
        rrotate_np(stack_a, stack_b);
        moves[max] = mrr;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_rrotate_np(stack_a, stack_b);
        rev_rotate_np(stack_a);
        moves[max] = mrra;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_rev_rotate_np(stack_a);
        rev_rotate_np(stack_b);
        moves[max] = mrrb;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_rev_rotate_np(stack_b);
        rev_rrotate_np(stack_a, stack_b);
        moves[max] = mrrr;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_rev_rrotate_np(stack_a, stack_b);
        swap_np(stack_a);
        moves[max] = msa;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_swap_np(stack_a);
        swap_np(stack_b);
        moves[max] = msb;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_swap_np(stack_b);
        sswap_np(stack_a, stack_b);
        moves[max] = mss;
        succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    }
    // if(!succesful)
    // {
    //     moves[max -1] = nm;
    //     un_sswap_np(stack_a, stack_b);
    //     push_np(stack_a, stack_b);
    //     moves[max] = mpa;
    //     succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    // }
    // if(!succesful)
    // {
    //     moves[max -1] = nm;
    //     if(ps_lstsize((*stack_a)) >= 1)
    //     {
    //         un_push_np(stack_b, stack_a);
    //     }
    //     push_np(stack_b, stack_a);
    //     moves[max] = mpb;
    //     succesful = recurse(max - 1, stack_a, stack_b, moves, size);
    // }
    // if(!succesful)
    // {
    //     moves[max -1] = nm;
    //     if(ps_lstsize((*stack_b)) >= 1)
    //         un_push_np(stack_a, stack_b);
    // }
    if(!succesful)
    {
        moves[max -1] = nm;
        un_sswap_np(stack_a, stack_b);
    }
    return(succesful);
}


int calc_max(t_pslist**stack_a)
{
    int size;

    size = ps_lstsize((*stack_a));
    if (size <= 3)
        return(size * (3/3));
    if (size <= 5)
        return(size * (12/5));
    if (size <= 100)
        return(size * (700/100));
    if (size > 100)
        return(size * (5500/500));
    return(size);
}

int push_b(t_pslist **stack_a, t_pslist **stack_b, int n)
{
    int index;
    int moves;

    moves = 0;
    index = 0;
    while(index < n)
    {
        if((*stack_a)->lds == 0)
        {
            push(stack_a, stack_b, pa);
            // recurse_sort_b
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

void recurse_sort(t_pslist **stack_a, t_pslist **stack_b)
{
    int max;
    int *moves;

    ft_printf("start\n----------\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');
    ft_printf("----------\n");
    sort_index(stack_a);
    max = calc_max(stack_a);
    ft_printf("max: %d\n", max);
    moves = malloc(sizeof(int) * max);
    if (moves == NULL)
        exit(EXIT_FAILURE);

    lds(stack_a);
    max -= push_b(stack_a, stack_b, ps_lstsize((*stack_a)));
    ft_printf("max: %d\n", max);
    // recurse(max, stack_a, stack_b, moves, ps_lstsize((*stack_a)));
    ft_printf("end\n----------\n");
    print_stack(stack_a, 'a');
    print_stack(stack_b, 'b');
    ft_printf("----------\n");
    for (int i = max; i > 0; i--)
    {
        if(moves[i] == mpa)
            ft_printf("pa\n");
        if(moves[i] == mpb)
            ft_printf("pb\n");
        if(moves[i] == mra)
            ft_printf("ra\n");
        if(moves[i] == mrb)
            ft_printf("rb\n");
        if(moves[i] == mrr)
            ft_printf("rr\n");
        if(moves[i] == mrra)
            ft_printf("rra\n");
        if(moves[i] == mrrr)
            ft_printf("rrr\n");
        if(moves[i] == msa)
            ft_printf("sa\n");
        if(moves[i] == msb)
            ft_printf("sb\n");
        if(moves[i] == mss)
            ft_printf("ss\n");
    }

}

