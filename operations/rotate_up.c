/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:12:12 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 14:49:25 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_all_elements_up(struct s_stack **stack)
{
	struct s_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = NULL;
	ps_lstadd_back(&tmp, *stack);
	*stack = tmp;
	(*stack)->previous = NULL;
}

void	ra(struct s_stack **stack)
{
	shift_all_elements_up(stack);
}

void	rb(struct s_stack **stack)
{
	shift_all_elements_up(stack);
}

void	rr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
