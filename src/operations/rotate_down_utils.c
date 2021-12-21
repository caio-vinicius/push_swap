/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:19:35 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/21 11:30:25 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrx_x(struct s_stack **stack,
	size_t amount,
	void (*operation)(struct s_stack **stack))
{
	while (amount)
	{
		operation(stack);
		amount--;
	}
}

void	rra_x(struct s_stack **stack, size_t amount)
{
	rrx_x(stack, amount, &rra);
}

void	rrb_x(struct s_stack **stack, size_t amount)
{
	rrx_x(stack, amount, &rrb);
}

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
