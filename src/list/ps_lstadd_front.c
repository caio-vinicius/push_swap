/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:36:57 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 14:44:59 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_front(struct s_stack **lst, struct s_stack *new)
{
	new->next = *lst;
	(*lst)->previous = new;
	*lst = new;
}
