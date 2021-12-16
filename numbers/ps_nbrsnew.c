/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nbrsnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:24:04 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/11 16:31:05 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_numbers *ps_nbrsnew(int count)
{
	struct s_numbers	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->numbers = malloc(count * sizeof(int));
	ft_memset(new->numbers, 0, count * sizeof(int));
	new->count = count;
	return (new);
}
