/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:05:06 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/15 22:56:28 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*count_digits(struct s_numbers *numbers, int exponent)
{
	int *digits;
	int digit;
	size_t i;

	digit = 0;
	i = 0;
	digits = malloc(10 * sizeof(int));
	ft_memset(digits, 0, 10 * sizeof(int));
	while (i != numbers->count)
	{
		digit = (numbers->numbers[i] / exponent) % 10;
		digits[digit] += 1; 
		i++;
	}
	return (digits);
}

static void	sort_sorted(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack *lst;
	size_t i;
	size_t j;

	lst = *stack_a;
	i = 0;
	j = 0;
	while (lst)
	{
		if (i == lst->index)
		{
			if (j > (ps_lstsize(*stack_a) / 2))
				rra_to_top(stack_a, lst);
			else
				ra_to_top(stack_a, lst);
			pb(stack_a, stack_b);
			i++;
			j = 0;
			lst = *stack_a;
		}
		else
		{
			j++;
			lst = lst->next;
		}
	}
	pa_all(stack_a, stack_b);
}

struct s_numbers	*count_sort(struct s_numbers *numbers, int exponent)
{
	struct s_numbers *output;
	int i;
	int j;
	int *digits;

	digits = count_digits(numbers, exponent);
	output = ps_nbrsnew(numbers->count);
	i = 0;
	j = 0;
	while (i < 10)
	{
		while (digits[i])
		{
			if (i == ((numbers->numbers[j] / exponent) % 10))
			{
				ps_nbrsadd_back(&output, numbers->numbers[j]);
				digits[i] -= 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(digits);
	ps_nbrsfree(numbers);
	return (output);
}

void	index_stack(struct s_stack **stack_a, struct s_numbers *numbers)
{
	struct s_stack	*lst;
	size_t	i;
	
	i = 0;
	lst = *stack_a;
	while (i != numbers->count)
	{
		while (lst)
		{
			if (lst->element == (int)numbers->numbers[i])
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

void	radix_sort(struct s_stack **stack_a, struct s_stack **stack_b, struct s_numbers *numbers)
{
	int highest_value;
	int exponent;

	highest_value = (ps_lsthighest(*stack_a))->element;
	exponent = 1;
	while ((highest_value / exponent) > 0)
	{
		numbers = count_sort(numbers, exponent);
		exponent = exponent * 10;
	}
	index_stack(stack_a, numbers);
	sort_sorted(stack_a, stack_b);
}
