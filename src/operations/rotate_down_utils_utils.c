/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down_utils_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:54:00 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/21 20:54:30 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrx_to_top(
	struct s_stack **stack,
	struct s_stack *lst,
	void (*operation)(struct s_stack **stack))
{
	while (lst->previous)
		if (lst != *stack)
			operation(stack);
}

void	rra_to_top(struct s_stack **stack_a, struct s_stack *lst)
{
	rrx_to_top(stack_a, lst, &rra);
}

void	rrb_to_top(struct s_stack **stack_b, struct s_stack *lst)
{
	rrx_to_top(stack_b, lst, &rrb);
}
