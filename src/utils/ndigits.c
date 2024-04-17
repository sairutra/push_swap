#include "../../inc/push_swap.h"
#include <stdio.h>

int get_digits(int value)
{
    int ret;
    
    value = value / 10;
    ret = 1;
    if(value > 0)
        ret += get_digits(value);
    return(ret);
}

int ndigits(t_pslist* stack)
{
    int         max_digits;
    int         digits;
    t_pslist    *temp;
    
    max_digits = 0;
    digits = 0;
    temp = stack;

    while(temp != NULL)
    {
        digits = get_digits(temp->content);
        if(digits > max_digits)
            max_digits = digits;
        temp = temp->next;
    }
    return(max_digits);
}
