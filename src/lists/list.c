#include "../shared/push_swap.h"

t_pslist	*ps_lstnew(int content)
{
	t_pslist	*new_node;

	new_node = malloc(sizeof(t_pslist));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ps_lstadd_front(t_pslist	**lst, t_pslist	*new)
{
	new->next = (*lst);
	(*lst) = new;
}

int	ps_lstsize(t_pslist *lst)
{
	int		size;
	t_pslist	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
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

void	ps_lstadd_back(t_pslist	**lst, t_pslist	*new)
{
	t_pslist	*last;

	last = ps_lstlast((*lst));
	if (last == NULL)
		(*lst) = new;
	else
		last->next = new;
}
