/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:21:56 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/03 17:46:02 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	if (is_min_value(data->stack_a[0], &data->stack_a[0], data->a_len))
	{
		sa_sort(data);
		ra_sort(data);
	}
	else if (is_max_value(data->stack_a[0], &data->stack_a[0], data->a_len))
	{
		ra_sort(data);
		if (!is_sorted(data))
			sa_sort(data);
	}
	else
	{
		if (is_min_value(data->stack_a[1], &data->stack_a[0], data->a_len))
			sa_sort(data);
		else
			rra_sort(data);
	}
}

void	sort_under_five(t_data *data)
{
	if (data->a_len < 3)
	{
		if (!is_sorted(data))
			sa_sort(data);
	}
	else if (data->a_len == 3)
	{
		if (!is_sorted(data))
			sort_three(data);
	}
	else
	{
		if (!is_sorted(data))
		{
			pb_sort(data);
			if (!is_sorted(data))
				sort_three(data);
			execute_moves_a(data);
		}
		move_smallest_top(data);
	}
}

void	sort_root(t_data *data)
{
	if (data->a_len < 5)
		sort_under_five(data);
	else
	{
		pb_sort(data);
		pb_sort(data);
		while (data->a_len > 3)
		{
			calc_cheapest(data);
			execute_moves_b(data);
		}
	}
	if (!is_sorted(data))
		sort_three(data);
	while (data->b_len != 0)
		execute_moves_a(data);
	if (!is_sorted(data))
		move_smallest_top(data);
}
