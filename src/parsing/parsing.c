/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:21:28 by csouza-f          #+#    #+#             */
/*   Updated: 2021/12/27 21:27:41 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	are_numbers(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]) && arr[i][j] != '-')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	are_integers(char **arr)
{
	char	*s;
	int		i;

	i = 0;
	while (arr[i])
	{
		s = ft_itoa(ft_atoi(arr[i]));
		if (ft_strncmp(s, arr[i], sizeof(arr[i])))
		{
			free(s);
			return (0);
		}
		free(s);
		i++;
	}
	return (1);
}

static int	theres_duplicates(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (arr[i])
	{
		while (arr[j])
		{
			if (!ft_strncmp(arr[i], arr[j], 10))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

struct s_numbers	*get_numbers(char **arr, int arrlen)
{
	struct s_numbers	*numbers;
	int					i;

	if (!are_numbers(arr))
		return (0);
	if (!are_integers(arr))
		return (0);
	if (theres_duplicates(arr))
		return (0);
	i = 0;
	numbers = ps_nbrsnew(arrlen);
	while (arr[i])
	{
		numbers->numbers[i] = ft_atoi(arr[i]);
		i++;
	}
	return (numbers);
}
