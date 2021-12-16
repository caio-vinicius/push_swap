#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

struct s_stack
{
	int		element;
	size_t		index;
	struct s_stack	*next;
	struct s_stack	*previous;
};

struct s_numbers
{
	int	*numbers;
	size_t	count;
};

/*
**
** List
**
*/

struct s_stack	*ps_lstnew(int element, size_t index);
struct s_stack	*ps_lstlast(struct s_stack *lst);
void		ps_lstadd_front(struct s_stack **lst, struct s_stack *new);
void		ps_lstadd_back(struct s_stack **lst, struct s_stack *new);
size_t		ps_lstsize(struct s_stack *lst);
struct s_stack	*ps_lsthighest(struct s_stack *stack);
void		ps_lstfree(struct s_stack *stack);
struct s_stack	*ps_llstnew(struct s_numbers *numbers);

/*
**
** Numbers
**
*/

void			ps_nbrsfree(struct s_numbers *nbrs);
struct s_numbers	*ps_nbrsnew(int count);
void			ps_nbrsadd_back(struct s_numbers **numbers, int number);

/*
**
** Parsing
**
*/

struct s_numbers	*get_numbers(char *arr[], int arrlen);

/*
**
** Sort
**
*/

void	radix_sort(struct s_stack **stack_a, struct s_stack **stack_b, struct s_numbers *numbers);
void	bubble_sort(struct s_stack *stack);

/*
**
** Operations
**
*/

void	sa(struct s_stack **stack);
void	sb(struct s_stack **stack);
void	ss(struct s_stack **stack_a, struct s_stack **stack_b);

void	pa(struct s_stack **stack_a, struct s_stack **stack_b);
void	pa_x(struct s_stack **stack_a, struct s_stack **stack_b, size_t amount);
void	pa_all(struct s_stack **stack_a, struct s_stack **stack_b);
void	pb(struct s_stack **stack_a, struct s_stack **stack_b);
void	pb_x(struct s_stack **stack_a, struct s_stack **stack_b, size_t amount);

void	ra(struct s_stack **stack);
void	ra_x(struct s_stack **stack, size_t amount);
void	ra_to_top(struct s_stack **stack_a, struct s_stack *lst);
void	rb(struct s_stack **stack);
void	rb_x(struct s_stack **stack, size_t amount);
void	rr(struct s_stack **stack_a, struct s_stack **stack_b);
void	rra(struct s_stack **stack);
void	rra_x(struct s_stack **stack, size_t amount);
void	rra_to_top(struct s_stack **stack_a, struct s_stack *lst);
void	rrb(struct s_stack **stack);
void	rrb_x(struct s_stack **stack, size_t amount);
void	rrr(struct s_stack **stack_a, struct s_stack **stack_b);

/*
**
** Utils
**
*/

int	stack_is_sorted_ascending(struct s_stack *stack);

#endif
