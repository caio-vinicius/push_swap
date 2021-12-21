/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:05:06 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/21 11:37:01 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			lst = *stack_a;
		}
		else
		{
			j++;
			lst = lst->next;
		}
	}
}

static struct s_numbers *get_chunks(struct s_stack *stack_a)
{
	struct s_numbers *chunks;
	int size_chunk;
	size_t i;

	#define CHUNKS 10
	size_chunk = ps_lstsize(stack_a) / CHUNKS;
	chunks = ps_nbrsnew(CHUNKS + 1);
	i = 1;
	while (i < chunks->count)
	{
		chunks->numbers[i] = size_chunk * i;
		i++;
	}
	return (chunks);
}

int	get_smallest_number(struct s_numbers *numbers)
{
	size_t i;
	int smallest_number;

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

void	move_value_closer_from_top_to_top(
	struct s_stack **stack,
	struct s_stack *value1,
	struct s_stack *value2)
{
	struct s_numbers *numbers;
	int smallest_number;
	size_t i;
	int size;

	size = 0;
	if (value1 || value2)
		if (value1)
			size += 2;
		else if (value2)
			size += 2;	
	else
		return ;

	numbers = ps_nbrsnew(size);
	numbers->numbers[0] = ps_lstrsize(value1);
	numbers->numbers[1] = ps_lstsize(value1);
	numbers->numbers[2] = ps_lstrsize(value2);
	numbers->numbers[3] = ps_lstsize(value2);
	i = 0;
	smallest_number = get_smallest_number(numbers);
	while (i != numbers->count)
	{
		if (numbers->numbers[i] == smallest_number)
		{
			if (i == 0)
				ra_to_top(stack, value1);
			else if (i == 1)
				rra_to_top(stack, value1);
			else if (i == 2)
				ra_to_top(stack, value2);
			else if (i == 3)
				rra_to_top(stack, value2);
			break ;
		}
		i++;
	}
	ps_nbrsfree(numbers);
}

struct s_numbers	*count_chunks(struct s_stack *stack, struct s_numbers *chunks)
{
	size_t i;
	struct s_stack *lst;
	struct s_numbers *counted_chunks;

	i = 0;
	lst = stack;
	counted_chunks = ps_nbrsnew(chunks->count);
	while (i != chunks->count)
	{
		while (lst)
		{
			if (lst->index >= chunks->numbers[i] && lst->index <= (chunks->numbers[i + 1] - 1))
				counted_chunks->numbers[i] += 1;	
			lst = lst->next;
		}
		i++;
		lst = stack;
	}
	return (counted_chunks);
}

static void	sort_sorted_big(
		struct s_stack **stack_a,
		struct s_stack **stack_b)
{
	struct s_stack *lst;
	struct s_stack *value1;
	struct s_stack *value2;
	struct s_numbers *chunks;
	struct s_numbers *counted_chunks;
	int i;
	size_t start;
	size_t end;
	
	chunks = get_chunks(*stack_a);
	counted_chunks = count_chunks(*stack_a, chunks);
	lst = *stack_a;
	i = 0;
	value1 = NULL;
	value2 = NULL;
	while (lst)
	{
		while (counted_chunks->numbers[i])
		{
			start = chunks->numbers[i];
			end = chunks->numbers[i + 1] - 1;
			while (lst)
			{
				if (lst->index >= start && lst->index <= end)
				{
					if (!value1)
						value1 = lst;
					else if (!value2)
						value2 = lst;
					else
						break ;
				}
				lst = lst->next;
			}
			move_value_closer_from_top_to_top(stack_a, value1, value2);
			pb(stack_a, stack_b);
			counted_chunks->numbers[i] -= 1; 
			value1 = NULL;
			value2 = NULL;
			lst = *stack_a;
		}
		i++;
	}
}

void	radix_sort(
	struct s_stack **stack_a,
	struct s_stack **stack_b,
	struct s_numbers *numbers)
{
	int	highest_value;
	int	exponent;
	struct s_stack	*highest_node;

	highest_value = (ps_lsthighest(*stack_a))->element;
	exponent = 1;
	while ((highest_value / exponent) > 0)
	{
		numbers = count_sort(numbers, exponent);
		exponent = exponent * 10;
	}
	index_stack(stack_a, numbers);
	ps_nbrsfree(numbers);
	//sort_sorted(stack_a, stack_b);
	sort_sorted_big(stack_a, stack_b);
	while (*stack_b)
	{
		highest_node = ps_lsthighest(*stack_b);
		if (ps_lstrsize(highest_node) > (ps_lstsize(*stack_b) / 2))
			rrb_to_top(stack_b, highest_node);
		else
			rb_to_top(stack_b, highest_node);
		pa(stack_a, stack_b);
	}
	//pa_all(stack_a, stack_b);
}
