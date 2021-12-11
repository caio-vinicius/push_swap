#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

struct s_stack
{
	int		element;
	struct s_stack	*next;
	struct s_stack	*previous;
};

struct s_numbers
{
	int	*numbers;
	size_t	count;
};

struct s_stack	*ps_lstnew(int element);
struct s_stack	*ps_lstlast(struct s_stack *lst);
void		ps_lstadd_front(struct s_stack **lst, struct s_stack *new);
void		ps_lstadd_back(struct s_stack **lst, struct s_stack *new);

int	*get_numbers(char *arr[], int arrlen);

/*
**
** Operations
**
*/

void	sa(struct s_stack *stack);
void	sb(struct s_stack *stack);
void	ss(struct s_stack *stack_a, struct s_stack *stack_b);

void	pa(struct s_stack **stack_a, struct s_stack **stack_b);
void	pb(struct s_stack **stack_a, struct s_stack **stack_b);

void	ra(struct s_stack **stack);
void	rb(struct s_stack **stack);
void	rr(struct s_stack **stack_a, struct s_stack **stack_b);
void	rra(struct s_stack **stack);
void	rrb(struct s_stack **stack);
void	rrr(struct s_stack **stack_a, struct s_stack **stack_b);

#endif
