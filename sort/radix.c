/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:05:06 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/11 11:18:49 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*count_digits(struct s_stack *stack, int exponent)
{
	int *digits;
	int digit;
	size_t i;

	digit = 0;
	i = 0;
	digits = malloc(10 * sizeof(int));
	ft_memset(digits, 0, 10 * sizeof(int));
	while (stack)
	{
		digit = (stack->element / exponent) % 10;
		digits[digit] += 1; 
		stack = stack->next;
		i++;
	}
	return (digits);
}

static int	*find_positions(int *digits)
{
	int i;
	int *position;
	
	i = 1;
	position = malloc(10 * sizeof(int));
	ft_memset(position, 0, 10 * sizeof(int));
	while (i < 10) {
		position[i] = digits[i - 1] + position[i - 1];
		i++;
	}
	return (position);
}

static struct s_stack	*count_sort(struct s_stack *stack, int stack_size, int exponent)
{
	int *digits;
	struct s_numbers *output;
	struct s_stack *lst;
	int *position;
	int digit;
	int i;

	digits = count_digits(stack, exponent);
	output = malloc(sizeof(*output));
	output->numbers = malloc(stack_size * sizeof(int));
	ft_memset(output->numbers, 0, stack_size * sizeof(int));
	output->count = stack_size;
	position = find_positions(digits);
	free(digits);
	i = 0;
	while (stack)
	{
		digit = (stack->element / exponent) % 10;
		while (output->numbers[position[digit]+i])
			i++;
		output->numbers[position[digit]+i] = stack->element;
		i = 0;
		stack = stack->next;
	}
	free(position);
	lst = ps_llstnew(output);
	free(output->numbers);	
	free(output);	
	return (lst);
}

struct s_stack	*radix_sort(struct s_stack *stack)
{
	int stack_size;
	int highest_value;
	int exponent;
	struct s_stack *lst;

	stack_size = ps_lstsize(stack);
	highest_value = (ps_lsthighest(stack))->element;
	exponent = 1;
	while ((highest_value / exponent) > 0)
	{
		lst = stack;
		stack = count_sort(stack, stack_size, exponent);
		ps_lstfree(lst);
		exponent = exponent * 10;
	}
	return (stack);
}
