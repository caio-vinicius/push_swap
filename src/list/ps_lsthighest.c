/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lsthighest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:08:07 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/11 11:10:51 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*ps_lsthighest(struct s_stack *stack)
{
	struct s_stack	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->element > highest->element)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}
