/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:02:47 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/22 16:39:01 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sorted_move(struct s_stack **stack_a,
			struct s_stack **stack_b,
			struct s_stack **values);

static struct s_numbers	*get_chunks(
	struct s_stack *stack_a,
	int amount_chunks)
{
	struct s_numbers	*chunks;
	int					size_chunk;
	size_t				i;

	size_chunk = ps_lstsize(stack_a) / amount_chunks;
	chunks = ps_nbrsnew(amount_chunks + 1);
	i = 1;
	while (i < chunks->count)
	{
		chunks->numbers[i] = size_chunk * i;
		i++;
	}
	return (chunks);
}

static struct s_numbers	*count_chunks(
	struct s_stack *stack,
	struct s_numbers *chunks)
{
	struct s_numbers	*counted_chunks;
	struct s_stack		*lst;

	lst = stack;
	counted_chunks = ps_nbrsnew(chunks->count);
	while (chunks->count)
	{
		chunks->count--;
		while (lst)
		{
			if (lst->index <= (size_t)(chunks->numbers[chunks->count + 1] - 1)
				&& lst->index >= (size_t)chunks->numbers[chunks->count])
				counted_chunks->numbers[chunks->count] += 1;
			lst = lst->next;
		}
		lst = stack;
	}
	return (counted_chunks);
}

static void	pa_all_selecting_larger_numbers(
	struct s_stack **stack_a,
	struct s_stack **stack_b)
{
	struct s_stack	*highest_node;

	while (*stack_b)
	{
		highest_node = ps_lsthighest(*stack_b);
		if (ps_lstrsize(highest_node) > (ps_lstsize(*stack_b) / 2))
			rrb_to_top(stack_b, highest_node);
		else
			rb_to_top(stack_b, highest_node);
		pa(stack_a, stack_b);
	}
}

static void	sort_sorted_big(
		struct s_stack **stack_a,
		struct s_stack **stack_b,
		struct s_numbers *chunks,
		struct s_numbers *counted_chunks)
{
	struct s_stack	*lst;
	struct s_stack	**values;
	int				i;
	int				j;

	values = malloc(sizeof(*values) * 2);
	i = 0;
	while (*stack_a)
	{
		while (counted_chunks->numbers[i] && counted_chunks->numbers[i]--)
		{
			lst = *stack_a;
			j = 0;
			while (lst && j < 2)
			{
				if (lst->index <= (size_t)(chunks->numbers[i + 1] - 1)
					&& lst->index >= (size_t)chunks->numbers[i])
					values[j++] = lst;
				lst = lst->next;
			}
			sort_sorted_move(stack_a, stack_b, values);
		}
		i++;
	}
	free(values);
}

void	sort_big(
	struct s_stack **stack_a,
	struct s_stack **stack_b,
	int stack_size)
{
	struct s_numbers	*chunks;
	struct s_numbers	*counted_chunks;
	int					amount_chunks;

	amount_chunks = 5;
	if (stack_size >= 500)
		amount_chunks = 10;
	chunks = get_chunks(*stack_a, amount_chunks);
	counted_chunks = count_chunks(*stack_a, chunks);
	sort_sorted_big(stack_a, stack_b, chunks, counted_chunks);
	ps_nbrsfree(chunks);
	ps_nbrsfree(counted_chunks);
	pa_all_selecting_larger_numbers(stack_a, stack_b);
}
