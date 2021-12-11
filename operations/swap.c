/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:16:19 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/30 21:54:41 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_first_two_elements(struct s_stack **stack)
{
	struct s_stack *tmp;

	tmp = (*stack)->next;
	if ((*stack)->next->next)
		(*stack)->next->next->previous = *stack;
	(*stack)->previous = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->previous = NULL;
	tmp->next = NULL;
	ps_lstadd_front(stack, tmp);
}

void	sa(struct s_stack **stack)
{
	swap_first_two_elements(stack);
	ft_putstr("sa\n");
}

void	sb(struct s_stack **stack)
{
	swap_first_two_elements(stack);
	ft_putstr("sb\n");
}

void	ss(struct s_stack **stack_a, struct s_stack **stack_b)
{
	swap_first_two_elements(stack_a);
	swap_first_two_elements(stack_b);
	ft_putstr("ss\n");
}
