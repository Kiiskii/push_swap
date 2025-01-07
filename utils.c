/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:56:56 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/03 10:12:51 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_smallest_top(t_data *data)
{
	size_t	i;

	data->mid_a = (data->a_len - 1) / 2;
	find_max_min(data, &data->stack_a[0], data->a_len);
	i = data->max_i + 1;
	if (i <= data->mid_a)
	{
		while (i != 0)
		{
			ra_sort(data);
			i--;
		}
	}
	else
	{
		while (i != data->a_len)
		{
			rra_sort(data);
			i++;
		}
	}
}

bool	is_sorted(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->a_len - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	is_max_value(int curr_index, int *array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (curr_index < array[i])
			return (false);
		i++;
	}
	return (true);
}

bool	is_min_value(int curr_index, int *array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (curr_index > array[i])
			return (false);
		i++;
	}
	return (true);
}
