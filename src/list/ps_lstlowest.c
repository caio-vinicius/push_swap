/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstlowest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:39:58 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/24 10:40:07 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*ps_lstlowest(struct s_stack *stack)
{
	struct s_stack	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->element < lowest->element)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}
