/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_utils_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:56:09 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/21 20:56:17 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rx_to_top(
	struct s_stack **stack,
	struct s_stack *lst,
	void (*operation)(struct s_stack **stack))
{
	while (lst->previous)
		if (lst != *stack)
			operation(stack);
}

void	ra_to_top(struct s_stack **stack_a, struct s_stack *lst)
{
	rx_to_top(stack_a, lst, &ra);
}

void	rb_to_top(struct s_stack **stack_b, struct s_stack *lst)
{
	rx_to_top(stack_b, lst, &rb);
}
