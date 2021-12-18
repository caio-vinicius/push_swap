/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:17:00 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/18 16:47:15 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	px_x(struct s_stack **stack_a,
	struct s_stack **stack_b,
	size_t amount,
	void (*operation)(struct s_stack **stack_a, struct s_stack **stack_b))
{
	while (amount)
	{
		operation(stack_a, stack_b);
		amount--;
	}
}

void	pa_x(struct s_stack **stack_a, struct s_stack **stack_b, size_t amount)
{
	px_x(stack_a, stack_b, amount, &pa);
}

void	pb_x(struct s_stack **stack_a, struct s_stack **stack_b, size_t amount)
{
	px_x(stack_a, stack_b, amount, &pb);
}

void	pa_all(struct s_stack **stack_a, struct s_stack **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
}
