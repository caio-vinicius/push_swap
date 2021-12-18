/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_llstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:16:39 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/18 16:43:37 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*ps_llstnew(struct s_numbers *numbers)
{
	struct s_stack	*stack;
	struct s_stack	*new;
	size_t			i;

	i = 0;
	if (!numbers)
		return (ps_lstnew(0, 0));
	stack = ps_lstnew(numbers->numbers[i], 0);
	i++;
	while (i < numbers->count)
	{
		new = ps_lstnew(numbers->numbers[i], 0);
		if (!new)
		{
			ps_lstfree(stack);
			return (NULL);
		}
		ps_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}
