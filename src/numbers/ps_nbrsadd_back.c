/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nbrsadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:50:08 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/23 16:29:06 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_nbrsadd_back(
	struct s_numbers **numbers,
	int number,
	size_t zero_amount)
{
	size_t	i;

	i = 0;
	while (!ft_isdigit((*numbers)->numbers[i]))
	{
		if ((*numbers)->numbers[i] == 0 && zero_amount > 0)
			zero_amount--;
		else if (zero_amount == 0 && !(*numbers)->numbers[i])
			break ;
		i++;
	}
	(*numbers)->numbers[i] = number;
}
