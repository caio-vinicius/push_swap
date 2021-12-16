/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:11:55 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/15 23:16:58 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element_to_top(struct s_stack **taker, struct s_stack **giver)
{	
	struct s_stack	*tmp;
	
	if (!*giver)
		return ;
	tmp = (*giver)->next;
	if (*taker)
		ps_lstadd_front(taker, *giver);
	else
	{
		*taker = *giver;
		(*taker)->next = NULL;
	}
	*giver = tmp;
	if (*giver)
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
