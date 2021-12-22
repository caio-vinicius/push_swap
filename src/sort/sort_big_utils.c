/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:23:50 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/22 16:05:13 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct s_numbers	*make_numbers(
	struct s_stack **values)
{
	struct s_numbers	*numbers;	
	int					size;

	size = 0;
	if (values[0])
		size += 2;
	else if (values[1])
		size += 2;
	numbers = ps_nbrsnew(size + 1);
	numbers->numbers[0] = ps_lstrsize(values[0]);
	numbers->numbers[1] = ps_lstsize(values[0]);
	numbers->numbers[2] = ps_lstrsize(values[1]);
	numbers->numbers[3] = ps_lstsize(values[1]);
	return (numbers);
}

static int	get_smallest_number(
	struct s_numbers *numbers)
{
	size_t	i;
	int		smallest_number;

	i = 1;
	smallest_number = numbers->numbers[0];
	while (i != numbers->count)
	{
		if (numbers->numbers[i] < smallest_number)
			smallest_number = numbers->numbers[i];
		i++;
	}
	return (smallest_number);
}

static void	ra_or_rra_closer_from_top(
	struct s_stack **stack,
	struct s_stack **values)
{
	struct s_numbers	*numbers;
	int					smallest_number;
	size_t				i;

	i = 0;
	numbers = make_numbers(values);
	smallest_number = get_smallest_number(numbers);
	while (i != numbers->count)
	{
		if (numbers->numbers[i] == smallest_number)
		{
			if (i == 0)
				ra_to_top(stack, values[0]);
			else if (i == 1)
				rra_to_top(stack, values[0]);
			else if (i == 2)
				ra_to_top(stack, values[1]);
			else if (i == 3)
				rra_to_top(stack, values[1]);
			break ;
		}
		i++;
	}
	ps_nbrsfree(numbers);
}

void	sort_sorted_move(
	struct s_stack **stack_a,
	struct s_stack **stack_b,
	struct s_stack **values)
{
	ra_or_rra_closer_from_top(stack_a, values);
	pb(stack_a, stack_b);
}
