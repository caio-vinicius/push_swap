/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:11:39 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/11 11:20:01 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_ordered(struct s_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->element > stack->next->element)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	push_swap(int nbrslen, char **nbrs)
{
	struct s_stack	*stack_a;
	//struct s_stack	*stack_a_last;
	//struct s_stack	*stack_b;
	struct s_numbers	*numbers;

	numbers = get_numbers(++nbrs, --nbrslen);
	if (!numbers)
	{
		ft_putstr("Error\n");
		return (EXIT_FAILURE);
	}
	stack_a = ps_llstnew(numbers);
	//stack_b = new_stack(numbers);
	free(numbers->numbers);
	free(numbers);
	//bubble_sort(stack_a);
	//stack_a_last = ps_lstlast(stack_a);
	//quick_sort(stack_a, stack_a_last);
	stack_a = radix_sort(stack_a);
	if (!is_ordered(stack_a)) {
		ps_lstfree(stack_a);
		ft_putstr("Not ordered");
		return (EXIT_FAILURE);
	} else {
		ps_lstfree(stack_a);
		ft_putstr("Ordered!");
		return (EXIT_SUCCESS);
	}
	//sa(stack_a);
	//sb(stack_b);
	//ss(stack_a, stack_b);
	//pa(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//ra(&stack_a);
	//rb(&stack_b);
	//rr(&stack_a, &stack_b);
	//rra(&stack_a);
	//rrb(&stack_b);
	//rrr(&stack_a, &stack_b);
	ps_lstfree(stack_a);
	//free_stack(stack_b);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (push_swap(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
