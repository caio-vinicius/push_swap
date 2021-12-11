/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:12:12 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 20:57:18 by csouza-f         ###   ########.fr       */
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
	ft_putstr("ra\n");
}

void	rb(struct s_stack **stack)
{
	shift_all_elements_up(stack);
	ft_putstr("rb\n");
}

void	rr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	shift_all_elements_up(stack_a);
	shift_all_elements_up(stack_b);
	ft_putstr("rr\n");
}
