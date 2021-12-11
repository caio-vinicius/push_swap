/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:20:03 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/11 11:20:13 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(struct s_stack *stack)
{
	int stack_len;
	struct s_stack *lst;
	struct s_stack *current;
	int amount;
	int amount2;
	
	stack_len = ps_lstsize(stack);
	lst = stack;
	amount = 0;
	amount2 = 0;
	while (stack_len) {
		while (stack->next) {
			if (stack->element > stack->next->element) {
				current = stack;
				while (stack->previous) {
					amount++;
					amount2++;
					stack = stack->previous;
				}
				while (amount) {
					ra(&lst);
					amount--;
				}
				sa(&lst);
				while (amount2) {
					rra(&lst);
					amount2--;
				}
				stack = current;
			} else {
				stack = stack->next;
			}
		}
		stack = lst;
		stack_len--;
	}
}
