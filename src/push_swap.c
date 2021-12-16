/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:11:39 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/15 23:59:08 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int nbrslen, char **nbrs)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_numbers	*numbers;

	numbers = get_numbers(++nbrs, --nbrslen);
	if (!numbers)
	{
		ft_putstr("Error\n");
		return (EXIT_FAILURE);
	}
	stack_a = ps_llstnew(numbers);
	stack_b = NULL;
	radix_sort(&stack_a, &stack_b, numbers);
	if (!stack_is_sorted_ascending(stack_a)) {
		ps_lstfree(stack_a);
		return (EXIT_FAILURE);
	} else {
		ps_lstfree(stack_a);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (push_swap(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
