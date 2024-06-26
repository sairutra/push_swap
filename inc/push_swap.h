/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:09:32 by spenning          #+#    #+#             */
/*   Updated: 2024/05/04 17:54:18 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/inc/libft.h"

//This struct is used as a list data structure for sorting the input of the 
// program. It has the following members, which are used in the following
// algoritms:
//
// int content (all)
// int index (radix, recurse)
// int lds (recurse)
// int lis (cal_sort)
// int binary (radix)
// struct s_pslist	*next (all)
//
// content:
// This is the actual content of the node itself, in order words, this is the
// value that needs to be sorted in relationship to the other nodes.
// index:
// the index member is assigned with the sort_index() function, in order to
// assign each node an index based on it's content in ascending order 
// in relation to the rest of the list that needs to be sorted
// lds:
// the lds (longest descending sequence) member is assigned with 
// the lds() function. This member acts as a flag to indicate that 
// the particular node is part of a lds.
// lis
// the lis (longest increasing sequence) member is assigned with 
// the lis() function. This member acts as a flag to indicate that the 
// particular node is part of a lis.
// binary:
// this member is used in combination with the index member. This member will
// hold the binary representation of the index value. So it can be used in 
// radix to sort in base 2. 
// next:
// this is a pointer to the next node in the list. If value of next is
// NULL then it is at the end of the list.
typedef struct s_pslist
{
	int				content;
	int				index;
	int				lds;
	int				lis;
	long long int	binary;
	struct s_pslist	*next;
}	t_pslist;

//This struct is used as a list data structure in order to save all 
// the moves, instead of executing the move. It has the following members, 
// which are used in the following algoritms:
//
// int	move (recurse)
// struct s_moves	*next (recurse)
typedef struct s_moves
{
	int				move;
	struct s_moves	*next;
}	t_moves;

//This is an enum to have names for stacka and b for readability. 
enum e_stack
{
	stacka,
	stackb
};

//This is an enum to have names for the swap operations for readability. 
enum e_swap
{
	ss,
	sa,
	sb
};

//This is an enum to have names for the push operations for readability. 
enum e_push
{
	pa,
	pb
};

//This is an enum to have names for the rotate operations for readability. 
enum e_rotate
{
	ra,
	rb,
	rr
};

//This is an enum to have names for the rrotate operations for readability. 
enum e_rrotate
{
	rra,
	rrb,
	rrr
};

//This is an enum to have names for the moves for readability. This enum is 
//mostly used in the recurse algoritm.
enum e_moves
{
	nm,
	msa,
	msb,
	mss,
	mpa,
	mpb,
	mra,
	mrb,
	mrr,
	mrra,
	mrrb,
	mrrr
};

// checker

// Function checks if the char pointer test is 
// an acceptable argument.
int			check_stack_argument_val(char *test);
// Function checks if the char pointer test is 
// not overflowing the int value for the stack. 
int			check_stack_argument_int(char *test);
// Function takes double char array, then checks
// all strings with check_stack_argument_val and 
// check_stack_argument_int.
int			check_stack_arguments(char **argv);
// Function takes double char array, then checks
// for duplicates in argv.
int			check_stack_duplicate(char **argv);
// Function takes double char array, calls
// check_stack_duplicate and check_stack_arguments
int			check_stack(char **argv);

// lists

// Function takes in a int (content) and returns a t_pslist node
// with the content (int) as the content member of the node 
// (node->content).
// Function has failed when return value is NULL.
t_pslist	*ps_lstnew(int content);
// Function takes in a pointer t_pslist (lst) and returns size
// in int.
int			ps_lstsize(t_pslist *lst);
// Function takes in a pointer t_pslist (lst) and returns pointer to
// last node in list. If lst is NULL then function will return NULL
// otherwise function will find last node in which ->next member is NULL
// and return node. 
t_pslist	*ps_lstlast(t_pslist	*lst);
// Function takes in a double pointer t_pslist (lst) and a pointer
// to a node to be added to the front of the list (new). new->next 
// points to beginning of list and pointer of lst becomes new,
// in order to become the new head. 
void		ps_lstadd_front(t_pslist	**lst, t_pslist	*new);
// Function takes in a double pointer t_pslist (lst) and a pointer
// to a node to be added to the back of the list (new). Function
// uses ps_lstlast function to find last node, if list is empty, 
// then new will become new head, otherwise new is added to end of lst
void		ps_lstadd_back(t_pslist	**lst, t_pslist	*new);
// Function takes in a double pointer t_pslist (lst). It will iterate
// over stack and put ->content to 0 and frees nodes.
void		ps_lstclear(t_pslist	**lst);
// Function takes in a pointer t_pslist (lst). It will put ->content to 0 
// and frees lst.
void		ps_lstdelone(t_pslist	*lst);
// Function takes in a pointer t_pslist (lst). It will return pointer t_pslist
// to the last node of the list. If list is empty it will return NULL.
t_pslist	*ps_lstlast(t_pslist	*lst);
// Function takes in a pointer t_pslist (lst). It will return pointer t_pslist
// to the second to last node of the list. If list is empty it will return NULL.
// If list only has two nodes it will return NULL.
t_pslist	*ps_lst_second_last(t_pslist	*lst);

// Function takes in a double pointer t_moves (lst) and a pointer
// to a node to be added to the front of the list (new). new->next 
// points to beginning of list and pointer of lst becomes new,
// in order to become the new head. 
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
void		mv_lstadd_front(t_moves	**lst, t_moves	*new);
// Function takes in a double pointer t_moves (lst) and a pointer
// to a node to be added to the back of the list (new). Function
// uses mv_lstlast function to find last node, if list is empty, 
// then new will become new head, otherwise new is added to end of lst.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
void		mv_lstadd_back(t_moves	**lst, t_moves	*new);
// Function takes in a pointer t_moves (lst). It will return pointer t_moves
// to the second to last node of the list. If list is empty it will return NULL.
// If list only has two nodes it will return NULL.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
t_moves		*mv_lst_second_last(t_moves	*lst);
// Function takes in a pointer t_moves (lst). It will return pointer t_moves
// to the last node of the list. If list is empty it will return NULL.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
t_moves		*mv_lstlast(t_moves	*lst);
// Function takes in a pointer t_moves (lst). It will put ->content to 0 
// and frees lst.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
void		mv_lstdelone(t_moves	*lst);
// Function takes in a double pointer t_moves (lst). It will iterate
// over stack and put ->content to 0 and frees nodes.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
void		mv_lstclear(t_moves	**lst);
// Function takes in a pointer t_moves (lst) and returns size
// in int.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
int			mv_lstsize(t_moves *lst);
// Function takes in a int (content) and returns a t_moves node
// with the content (int) as the content member of the node 
// (node->content).
// Function has failed when return value is NULL.
// Function is exactly the same as ps_ equivalent, but used to save the
// moves instead of executing them.
t_moves		*mv_lstnew(int content);
// Function takes in a t_moves **(lst) and deletes the last node of a list, 
// and puts the second to last node's next member to null. Function uses
// mv_lst_second_last() in the background.
void		mv_dellast(t_moves	**lst);

// stack

// This function takes a pointer to a t_pslist, together with a 
// pointer to a double char array, in order to create a stack
// with all the strings in the double char array. Function uses
// a double pointer to llist so it can change values without returning
// the list. Function returns int, with 1 as failure, and 0 as success
// status.
int			create_stack(t_pslist **llist, char **argv);
// Function takes in a char pointer (v) and returns a t_pslist node.
// Function has failed when return value is NULL.
t_pslist	*create_node(char *v);

//operations

// This function takes a stacks and swaps the first
// two elements. Except if the stack only has one element
// then it does nothing. The print int determines which 
// operation it will print, {sa, sb}
void		swap(t_pslist **stack, int print);
// This function takes two stacks and then calls the swap
// function for both of them.
void		sswap(t_pslist **stack_a, t_pslist **stack_b);
// This function takes two stacks, and puts the first element
// of stack_1 on top of stack_2, if stack_1 is empty function
// does nothing. The print int determines which 
// operation it will print, {pa, pb}
void		push(t_pslist **stack_1, t_pslist **stack_2, int print);
// This function takes a stack, and puts the first element
// as the last element. if stack is made of only one element, 
// it will do nothing.
// The print int determines which operation it will print, {ra, rb}
void		rotate(t_pslist **stack, int print);
// This function takes two stacks and then calls the rotate
// function for both of them.
void		rrotate(t_pslist **stack_a, t_pslist **stack_b);
// This function takes a stack, and puts the last element
// as the first element. if stack is made of only one element, 
// it will do nothing.
// The print int determines which operation it will print, {rra, rrb}
void		rev_rotate(t_pslist **stack, int print);
// This function takes two stacks and then calls the rev_rotate
// function for both of them.
void		rev_rrotate(t_pslist **stack_a, t_pslist **stack_b);

// This function takes a stacks and swaps the first
// two elements. Except if the stack only has one element
// then it does nothing. the function will not print the move
void		swap_np(t_pslist **stack);
// This function takes two stacks and then calls the swap
// function for both of them. the function will not print the move
void		sswap_np(t_pslist **stack_a, t_pslist **stack_b);
// This function takes two stacks, and puts the first element
// of stack_1 on top of stack_2, if stack_1 is empty function
// does nothing. the function will not print the move
void		push_np(t_pslist **stack_1, t_pslist **stack_2);
// This function takes a stack, and puts the first element
// as the last element. if stack is made of only one element, 
// it will do nothing.
// the function will not print the move
void		rotate_np(t_pslist **stack);
// This function takes two stacks and then calls the rotate
// function for both of them. the function will not print the move
void		rrotate_np(t_pslist **stack_a, t_pslist **stack_b);
// This function takes a stack, and puts the last element
// as the first element. if stack is made of only one element, 
// it will do nothing.
// the function will not print the move
void		rev_rotate_np(t_pslist **stack);
// This function takes two stacks and then calls the rev_rotate
// the function will not print the move
void		rev_rrotate_np(t_pslist **stack_a, t_pslist **stack_b);

// This function reverses the swap_np 
void		un_swap_np(t_pslist **stack);
// This function reverses the sswap_np
void		un_sswap_np(t_pslist **stack_a, t_pslist **stack_b);
// This function reverses the push_np
void		un_push_np(t_pslist **stack_2, t_pslist **stack_1);
// This function reverses the rotate_np
void		un_rotate_np(t_pslist **stack);
// This function reverses the rrotate_np
void		un_rrotate_np(t_pslist **stack_a, t_pslist **stack_b);
// This function reverses the rev_rotate_np
void		un_rev_rotate_np(t_pslist **stack);
// This function reverses the rev_rrotate_np
void		un_rev_rrotate_np(t_pslist **stack_a, t_pslist **stack_b);
//algorithmes

void		bubble_sort(t_pslist	**stack_a, t_pslist	**stack_b);
void		radix(t_pslist	**stack_a, t_pslist	**stack_b);
void		recurse_sort(t_pslist **stack_a, t_pslist **stack_b);
int			cal_sort(t_pslist **stack_a, t_pslist **stack_b);
void		sort_small(t_pslist **stacka, t_pslist **stackb);

//lis 

int			lis(t_pslist **stack_a);
int			push_b_lis(t_pslist **stack_a, t_pslist **stack_b, int n);
//calculate

void		cal_a(int *a, t_pslist **stack_a, t_pslist **stack_b, int size_a);
void		cal_b(int *b, t_pslist **stack_b, int size_b);
//move

void		execute_move(t_pslist **sa, t_pslist **sb, int a, int b);
//recurse

int			recurse_rotate(int max, t_pslist **st[], t_moves **mv, int size);
int			recurse_push(int max, t_pslist **st[], t_moves **mv, int size);
int			recurse_swap(int max, t_pslist **st[], t_moves **mv, int size);
int			recurse(int max, t_pslist **st[], t_moves **mv, int size);
//utils

int			check_sorted_stack(t_pslist	**stack_a, t_pslist**stack_b);
int			check_n_sorted(t_pslist	**stack_a, int n, const char flag);
void		print_stack(t_pslist	**stack, char name);
int			ndigits(t_pslist *stack);
void		print_rank_stack(t_pslist	**stack, char name);
void		print_index_stack(t_pslist	**stack, char name);
void		sort_index(t_pslist **stack_a);
void		init_index(t_pslist **stack_a, int *stack_c, int len);
void		init_c(t_pslist **stack_a, int *stack_c);
void		print_index_lds_stack(t_pslist	**stack, char name);
void		print_index_lis_stack(t_pslist	**stack, char name);
int			calc_max(t_pslist**stack_a);
void		print_moves(int*a, int*b, int size_b);
int			maxnum(t_pslist **stack_a);
int			max(int a, int b);
int			min(int a, int b);
void		free2(void *f1, void *f2);
void		print_t_moves(t_moves **moves);
void		print_index_stack_binary(t_pslist	**stack, char name);
void		add_binary(t_pslist	**stack_a);
void		free_char_array(char **arr);
char		**init_argv(char **argv, int argc);


#endif
