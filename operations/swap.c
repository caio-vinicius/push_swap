/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:16:19 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 13:16:49 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two_elements(struct s_stack *stack)
{
	int	tmp;

	tmp = stack->element;
	stack->element = stack->next->element;
	stack->next->element = tmp;
}

void	sa(struct s_stack *stack)
{
	swap_first_two_elements(stack);
}

void	sb(struct s_stack *stack)
{
	swap_first_two_elements(stack);
}

void	ss(struct s_stack *stack_a, struct s_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
