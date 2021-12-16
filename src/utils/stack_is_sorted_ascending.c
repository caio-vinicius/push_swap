/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:55:13 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/15 23:58:59 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted_ascending(struct s_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->element > stack->next->element)
			return (0);
		stack = stack->next;
	}
	return (1);
}
