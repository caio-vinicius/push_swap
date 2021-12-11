/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:11:55 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 20:51:30 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element_to_top(struct s_stack **taker, struct s_stack **giver)
{	
	struct s_stack	*tmp;

	tmp = (*giver)->next;
	ps_lstadd_front(taker, *giver);
	*giver = tmp;
	(*giver)->previous = NULL;
}

void	pa(struct s_stack **stack_a, struct s_stack **stack_b)
{
	push_element_to_top(stack_a, stack_b);
	ft_putstr("pa\n");
}

void	pb(struct s_stack **stack_a, struct s_stack **stack_b)
{
	push_element_to_top(stack_b, stack_a);
	ft_putstr("pb\n");
}
