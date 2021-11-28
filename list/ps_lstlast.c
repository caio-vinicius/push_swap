/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:37:13 by csouza-f          #+#    #+#             */
/*   Updated: 2021/11/28 14:45:10 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*ps_lstlast(struct s_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}
