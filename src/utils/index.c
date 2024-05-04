/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:39:00 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 15:58:34 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ss_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	selection_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < n)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		ss_swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

void	init_c(t_pslist **stack_a, int *stack_c)
{
	t_pslist	*temp;
	int			index;

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

void	init_index(t_pslist **stack_a, int *stack_c, int len)
{
	t_pslist	*temp;
	int			index;

	index = 0;
	while (index < len)
	{
		temp = (*stack_a);
		while (temp != NULL)
		{
			if (stack_c[index] == temp->content)
			{
				temp->index = index;
				break ;
			}
			else
				temp = temp->next;
		}
		index++;
	}
}

void	sort_index(t_pslist **stack_a)
{
	int	*stack_c;
	int	len;

	len = ps_lstsize((*stack_a));
	stack_c = malloc(sizeof(int) * len);
	if (stack_c == NULL)
		exit(EXIT_FAILURE);
	init_c(stack_a, stack_c);
	selection_sort(stack_c, len);
	init_index(stack_a, stack_c, len);
	free(stack_c);
}
