/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:05:06 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/18 20:41:12 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_sorted(
		struct s_stack **stack_a,
		struct s_stack **stack_b)
{
	struct s_stack	*lst;
	size_t			i;
	size_t			j;

	lst = *stack_a;
	i = 0;
	j = 0;
	while (lst)
	{
		if (i == lst->index && ++i)
		{
			if (j > (ps_lstsize(*stack_a) / 2))
				rra_to_top(stack_a, lst);
			else
				ra_to_top(stack_a, lst);
			pb(stack_a, stack_b);
			j = 0;
			lst= *stack_a;
		}
		else
		{
			j++;
			lst = lst->next;
		}
	}
}

static struct s_numbers	*count_sort(
			struct s_numbers *numbers,
			int exponent)
{
	struct s_numbers	*output;
	size_t				i;
	int					j;

	output = ps_nbrsnew(numbers->count);
	i = 0;
	j = -9;
	while (j < 10)
	{
		while (i < numbers->count)
		{
			if (j == ((numbers->numbers[i] / exponent) % 10))
				ps_nbrsadd_back(&output, numbers->numbers[i]);
			i++;
		}
		i = 0;
		j++;
	}
	ps_nbrsfree(numbers);
	return (output);
}

static void	index_stack(
		struct s_stack **stack_a,
		struct s_numbers *numbers)
{
	struct s_stack	*lst;
	size_t			i;

	i = 0;
	lst = *stack_a;
	while (i != numbers->count)
	{
		while (lst)
		{
			if (lst->element == numbers->numbers[i])
			{
				lst->index = i;
				break ;
			}
			lst = lst->next;
		}		
		i++;
		lst = *stack_a;
	}
}

void	radix_sort(
	struct s_stack **stack_a,
	struct s_stack **stack_b,
	struct s_numbers *numbers)
{
	int	highest_value;
	int	exponent;

	highest_value = (ps_lsthighest(*stack_a))->element;
	exponent = 1;
	while ((highest_value / exponent) > 0)
	{
		numbers = count_sort(numbers, exponent);
		exponent = exponent * 10;
	}
	index_stack(stack_a, numbers);
	ps_nbrsfree(numbers);
	sort_sorted(stack_a, stack_b);
	pa_all(stack_a, stack_b);
}
