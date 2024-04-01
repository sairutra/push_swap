
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_pslist
{
	int				content;
	struct s_pslist	*next;
}	t_pslist;


enum e_swap{ss, sa, sb};
enum e_push{pa, pb};

// checker

// Function checks if the char pointer test is 
// an acceptable argument.
int check_stack_argument_val(char *test);
// Function checks if the char pointer test is 
// not overflowing the int value for the stack. 
int check_stack_argument_int(char *test);
// Function takes double char array, then checks
// all strings with check_stack_argument_val and 
// check_stack_argument_int.
int check_stack_arguments(char **argv);
// Function takes double char array, then checks
// for duplicates in argv.
int check_stack_duplicate(char **argv);
// Function takes double char array, calls
// check_stack_duplicate and check_stack_arguments
int check_stack(char **argv);

// lists

// Function takes in a int (content) and returns a t_pslist node
// with the content (int) as the content member of the node 
// (node->content).
// Function has failed when return value is NULL.
t_pslist	*ps_lstnew(int content);
// Function takes in a pointer t_pslist (lst) and returns size
// in int.
int	ps_lstsize(t_pslist *lst);
// Function takes in a pointer t_pslist (lst) and returns pointer to
// last node in list. If lst is NULL then function will return NULL
// otherwise function will find last node in which ->next member is NULL
// and return node. 
t_pslist	*ps_lstlast(t_pslist	*lst);
// Function takes in a double pointer t_pslist (lst) and a pointer
// to a node to be added to the front of the list (new). new->next 
// points to beginning of list and pointer of lst becomes new,
// in order to become the new head. 
void	ps_lstadd_front(t_pslist	**lst, t_pslist	*new);
// Function takes in a double pointer t_pslist (lst) and a pointer
// to a node to be added to the back of the list (new). Function
// uses ps_lstlast function to find last node, if list is empty, 
// then new will become new head, otherwise new is added to end of lst
void	ps_lstadd_back(t_pslist	**lst, t_pslist	*new);
// Function takes in a double pointer t_pslist (lst). It will iterate
// over stack and put ->content to 0 and frees nodes.
void	ps_lstclear(t_pslist	**lst);
// Function takes in a pointer t_pslist (lst). It will put ->content to 0 
// and frees lst.
void	ps_lstdelone(t_pslist	*lst);


// stack

// This function takes a pointer to a t_pslist, together with a 
// pointer to a double char array, in order to create a stack
// with all the strings in the double char array. Function uses
// a double pointer to llist so it can change values without returning
// the list. Function returns int, with 1 as failure, and 0 as success
// status.
int	create_stack(t_pslist **llist, char **argv);
// Function takes in a char pointer (v) and returns a t_pslist node.
// Function has failed when return value is NULL.
t_pslist *create_node(char *v);

//operations

// This function takes a stacks and swaps the first
// two elements. Except if the stack only has one element
// then it does nothing. The print int determines which 
// operation it will print, {sa, sb}
void	swap(t_pslist** stack, int print);
// This function takes two stacks and then calls the swap
// function for both of them.
void	sswap(t_pslist** stack_a, t_pslist** stack_b);
// This function takes two stacks, and puts the first element
// of stack_1 on top of stack_2, if stack_1 is empty function
// does nothing. The print int determines which 
// operation it will print, {pa, pb}
void push(t_pslist **stack_1, t_pslist **stack_2, int print);


#endif
