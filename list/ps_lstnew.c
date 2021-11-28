/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:38:16 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 14:43:30 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*ps_lstnew(int element)
{
	struct s_stack	*new;

	new = malloc(sizeof(struct s_stack *));
	if (!new)
		return (0);
	new->element = element;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
