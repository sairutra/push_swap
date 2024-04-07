#include "../../inc/push_swap.h"

t_pslist	*ps_lst_second_last(t_pslist	*lst)
{
	t_pslist	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	if (last->next->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}

t_pslist	*ps_lstlast(t_pslist	*lst)
{
	t_pslist	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
		{
			last = last->next;
			return (last);
		}
		last = last->next;
	}
	return (last);
}

