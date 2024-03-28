#include "../shared/push_swap.h"

void	ps_lstdelone(t_pslist	*lst, void (*del)(int))
{
	del(lst->content);
	free(lst);
}

void	ps_lstclear(t_pslist	**lst, void (*del)(int))
{
	t_pslist	*temp_frt;
	t_pslist	*temp_bck;

	if (!lst)
		return ;
	temp_frt = (*lst);
	temp_bck = (*lst);
	while (temp_bck)
	{
		temp_frt = temp_frt->next;
		del(temp_bck->content);
		free(temp_bck);
		temp_bck = temp_frt;
	}
	(*lst) = 0;
}

