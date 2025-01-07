/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:58:09 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/03 10:12:39 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_cost(size_t i, size_t target_i, t_data *data)
{
	size_t	total_cost;

	data->mid_a = (data->a_len - 1) / 2;
	data->mid_b = (data->b_len - 1) / 2;
	if (i <= data->mid_a && target_i <= data->mid_b)
	{
		if (i < target_i)
			total_cost = target_i;
		else
			total_cost = i;
	}
	else if (i > data->mid_a && target_i > data->mid_b)
	{
		if (data->a_len - i > data->b_len - target_i)
			total_cost = data->a_len - i;
		else
			total_cost = data->b_len - target_i;
	}
	else if (i <= data->mid_a && target_i > data->mid_b)
		total_cost = i + (data->b_len - target_i);
	else
		total_cost = target_i + (data->a_len - i);
	return (total_cost);
}

size_t	find_target_b(int curr_i, t_data *data)
{
	size_t	i;

	i = 0;
	if (curr_i > data->max || curr_i < data->min)
	{
		if (data->max_i == 0)
			return (0);
		return (data->max_i);
	}
	else
	{
		while (i < data->b_len - 1)
		{
			if (curr_i < data->stack_b[i] && curr_i > data->stack_b[i + 1])
				return (i + 1);
			i++;
		}
	}
	return (0);
}

void	find_max_min(t_data *data, int *array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (is_max_value(array[i], &array[0], len))
		{
			data->max = array[i];
			data->max_i = i;
		}
		if (is_min_value(array[i], &array[0], len))
			data->min = array[i];
		i++;
	}
}

void	calc_cheapest(t_data *data)
{
	size_t	i;
	size_t	target_i;
	size_t	cost;

	find_max_min(data, &data->stack_b[0], data->b_len);
	i = 0;
	while (i < data->a_len)
	{
		target_i = find_target_b(data->stack_a[i], data);
		cost = count_cost(i, target_i, data);
		if (i == 0 || cost < data->cheap_cost)
		{
			data->cheap_cost = cost;
			data->cheap_i = i;
			data->cheap_trgt = target_i;
		}
		i++;
	}
}
