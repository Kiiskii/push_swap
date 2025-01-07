/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:12:08 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/03 10:14:16 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_target_a(int curr_i, t_data *data)
{
	size_t	i;

	i = 0;
	if (curr_i > data->max || curr_i < data->min)
	{
		if (data->max_i == data->a_len - 1)
			return (0);
		return (data->max_i + 1);
	}
	else
	{
		while (i < data->a_len - 1)
		{
			if (curr_i > data->stack_a[i] && curr_i < data->stack_a[i + 1])
				return (i + 1);
			i++;
		}
	}
	return (0);
}

void	execute_moves_a(t_data *data)
{
	size_t	target_i;

	data->mid_a = (data->a_len - 1) / 2;
	find_max_min(data, &data->stack_a[0], data->a_len);
	target_i = find_target_a(data->stack_b[0], data);
	if (target_i <= data->mid_a)
	{
		while (target_i != 0)
		{
			ra_sort(data);
			target_i--;
		}
	}
	else if (target_i > data->mid_a)
	{
		while (target_i != data->a_len)
		{
			rra_sort(data);
			target_i++;
		}
	}
	pa_sort(data);
}
