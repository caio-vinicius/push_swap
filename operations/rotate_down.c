/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:13:29 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 20:56:52 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_all_elements_down(struct s_stack **stack)
{
	struct s_stack	*tmp;

	tmp = ps_lstlast(*stack);
	tmp->previous->next = NULL;
	ps_lstadd_front(stack, tmp);
	(*stack)->previous = NULL;
}

void	rra(struct s_stack **stack)
{
	shift_all_elements_down(stack);
	ft_putstr("rra\n");
}

void	rrb(struct s_stack **stack)
{
	shift_all_elements_down(stack);
	ft_putstr("rrb\n");
}

void	rrr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	shift_all_elements_down(stack_a);
	shift_all_elements_down(stack_b);
	ft_putstr("rra\n");
}
