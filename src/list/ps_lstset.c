/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:04:30 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/11 16:04:37 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstset(struct s_stack **lst, int element)
{
	struct s_stack *new;

	new = *lst;
	while (new)
	{
		new->element = element;
		new = new->next;
	}
}
