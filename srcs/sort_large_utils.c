/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:14:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/02/08 23:20:29 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *values, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[j] < values[i])
			{
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_num_chunks(int size)
{
	if (size >= 6 && size <= 9)
		return (3);
	else if (size >= 10 && size <= 100)
		return (5);
	else if (size >= 101 && size <= 250)
		return (7);
	return (10);
}
