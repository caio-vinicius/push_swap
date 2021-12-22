/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:06:14 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/22 15:21:31 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_sorted(
		struct s_stack **stack_a,
		struct s_stack **stack_b)
{
	struct s_stack	*lst;
	size_t			i;

	lst = *stack_a;
	i = 0;
	while (lst)
	{
		if (i == lst->index)
		{
			if (ps_lstrsize(*stack_a) > (ps_lstsize(*stack_a) / 2))
				rra_to_top(stack_a, lst);
			else
				ra_to_top(stack_a, lst);
			if (i != ps_lsthighest(*stack_a)->index)
				pb(stack_a, stack_b);
			i++;
			lst = *stack_a;
		}
		else
			lst = lst->next;
	}
}

static void	sort_sorted_three(struct s_stack **stack_a)
{
	struct s_stack	*smallest;
	struct s_stack	*lst;
	size_t			size;

	lst = *stack_a;
	while (lst)
	{
		if (lst->index == 0)
			smallest = lst;
		lst = lst->next;
	}
	size = ps_lstrsize(smallest);
	if (size <= 2)
	{
		if (size == 2)
			sa(stack_a);
	}
	else
		rra(stack_a);
	if (!stack_is_sorted_ascending(*stack_a))
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	sort_general(struct s_stack **stack_a, struct s_stack **stack_b)
{
	size_t	stack_size;

	stack_size = ps_lstsize(*stack_a);
	if (stack_size > 3)
	{
		sort_sorted(stack_a, stack_b);
		pa_all(stack_a, stack_b);
	}
	else
		sort_sorted_three(stack_a);
}
