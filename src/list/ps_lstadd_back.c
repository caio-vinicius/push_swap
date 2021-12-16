/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:36:41 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 20:19:17 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(struct s_stack **lst, struct s_stack *new)
{
	struct s_stack	*tmp;

	tmp = ps_lstlast(*lst);
	if (tmp != NULL)
	{
		tmp->next = new;
		tmp->next->previous = tmp;
	}
	else
		*lst = new;
}
