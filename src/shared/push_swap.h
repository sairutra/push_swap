
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_pslist
{
	int				content;
	struct s_pslist	*next;
}	t_pslist;


int check_stack_a_argument_val(char *test);
int check_stack_a_argument_int(char *test);
int check_stack_a_arguments(char **argv);
int check_stack_a_duplicate(char **argv);
int check_stack_a(char **argv);
t_pslist	*ps_lstnew(int content);
void	ps_lstadd_front(t_pslist	**lst, t_pslist	*new);
int	ps_lstsize(t_pslist *lst);
t_pslist	*ps_lstlast(t_pslist	*lst);
void	ps_lstadd_back(t_pslist	**lst, t_pslist	*new);
void	ps_lstclear(t_pslist	**lst);
void	ps_lstdelone(t_pslist	*lst);

#endif
