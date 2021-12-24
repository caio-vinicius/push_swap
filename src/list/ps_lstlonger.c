/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstlonger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:22:43 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/24 19:46:51 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digits(int element)
{
	int	digits;

	digits = 1;
	while (element)
	{
		element /= 10;
		digits++;
	}
	return (digits);
}

struct s_stack	*ps_lstlonger(struct s_stack *stack)
{
	struct s_stack	*longest;
	int				current;

	longest = stack;
	current = count_digits(longest->element);
	while (stack)
	{
		if (count_digits(stack->element) > current)
		{
			longest = stack;
			current = count_digits(longest->element);
		}
		stack = stack->next;
	}
	return (longest);
}
