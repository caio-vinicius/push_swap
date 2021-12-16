/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:20:44 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/15 23:21:06 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rx_x(struct s_stack **stack, size_t amount, void (*operation)(struct s_stack **stack))
{
	while (amount)
	{
		operation(stack);
		amount--;
	}
}

void	ra_x(struct s_stack **stack, size_t amount)
{
	rx_x(stack, amount, &ra);
}

void	rb_x(struct s_stack **stack, size_t amount)
{
	rx_x(stack, amount, &rb);
}

void	ra_to_top(struct s_stack **stack_a, struct s_stack *lst)
{
	while (lst->previous)
		if (lst != *stack_a)
			ra(stack_a);
}
