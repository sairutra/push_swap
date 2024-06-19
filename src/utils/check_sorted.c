/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/28 18:26:49 by spenning      #+#    #+#                 */
/*   Updated: 2024/06/19 21:18:32 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_n_sorted(t_pslist	**stack_a, int n, const char flag)
{
	int			sorted;
	t_pslist	*temp;
	int			index;

	index = 1;
	sorted = 1;
	temp = (*stack_a);
	while (temp->next != NULL && index < n)
	{
		if ((temp->content >= temp->next->content) && (flag == '+'))
			sorted = 0;
		if ((temp->content <= temp->next->content) && (flag == '-'))
			sorted = 0;
		temp = temp->next;
		index++;
	}
	if (index != n)
		sorted = 0;
	return (sorted);
}

int	check_sorted_stack(t_pslist	**stack_a, t_pslist**stack_b)
{
	t_pslist	*temp;
	int			ret;

	ret = 0;
	temp = (*stack_a);
	if ((*stack_b) == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp-> content < (*stack_b)->content)
			return (0);
		temp = temp->next;
	}
	if (check_n_sorted(stack_a, ps_lstsize((*stack_a)), '+'))
		ret = 1;
	if (!check_n_sorted(stack_b, ps_lstsize((*stack_b)), '-'))
		ret = 0;
	return (ret);
}
