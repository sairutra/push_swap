#include "../../inc/push_swap.h"

t_pslist	*ps_lstnew(int content)
{
	t_pslist	*new_node;

	new_node = ft_calloc(sizeof(t_pslist), 1);
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
