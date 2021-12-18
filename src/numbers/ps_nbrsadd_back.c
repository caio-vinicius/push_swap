/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nbrsadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:50:08 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/18 16:45:03 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_nbrsadd_back(struct s_numbers **numbers, int number)
{
	size_t	i;

	i = 0;
	while ((*numbers)->numbers[i])
		i++;
	(*numbers)->numbers[i] = number;
}
