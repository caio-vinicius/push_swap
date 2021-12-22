/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:06:14 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/21 19:02:53 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_sorted(
		struct s_stack **stack_a,
		struct s_stack **stack_b)
{
	struct s_stack	*lst;
	size_t			i;
	size_t			j;

	lst = *stack_a;
	i = 0;
	j = 0;
	while (lst)
	{
		if (i == lst->index && ++i)
		{
			if (j > (ps_lstsize(*stack_a) / 2))
				rra_to_top(stack_a, lst);
			else
				ra_to_top(stack_a, lst);
			pb(stack_a, stack_b);
			j = 0;
			lst = *stack_a;
		}
		else
		{
			j++;
			lst = lst->next;
		}
	}
}

void	sort_general(struct s_stack **stack_a, struct s_stack **stack_b)
{
	sort_sorted(stack_a, stack_b);
	pa_all(stack_a, stack_b);
}
