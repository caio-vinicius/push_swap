/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:11:39 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 20:26:41 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*new_stack(int *elements)
{
	struct s_stack	*stack;
	struct s_stack	*new;
	int				i;

	i = 0;
	if (!elements)
		return (ps_lstnew(0));
	stack = ps_lstnew(elements[i]);
	i++;
	while (elements[i])
	{
		new = ps_lstnew(elements[i]);
		if (!new)
			return (NULL);
		ps_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

int	push_swap(int nbrslen, char *nbrs[])
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	size_t			numbers_len;
	int				*numbers;

	numbers = get_numbers(++nbrs, --nbrslen);
	if (!numbers)
	{
		ft_putstr("Error\n");
		return (EXIT_FAILURE);
	}
	numbers_len = nbrslen;
	stack_a = new_stack(numbers);
	stack_b = new_stack(numbers);
	free(numbers);
	sa(stack_a);
	sb(stack_b);
	ss(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ra(&stack_a);
	rb(&stack_b);
	rr(&stack_a, &stack_b);
	rra(&stack_a);
	rrb(&stack_b);
	rrr(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	if (push_swap(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
