/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:52:24 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/03 10:19:27 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_above_mid(t_data *data)
{
	while (data->cheap_i != 0 && data->cheap_trgt != 0)
	{
		rr_sort(data);
		data->cheap_i--;
		data->cheap_trgt--;
	}
	while (data->cheap_i != 0)
	{
		ra_sort(data);
		data->cheap_i--;
	}
	while (data->cheap_trgt != 0)
	{
		rb_sort(data);
		data->cheap_trgt--;
	}
}

void	both_below_mid(t_data *data)
{
	while (data->cheap_i != data->a_len && data->cheap_trgt != data->b_len)
	{
		rrr_sort(data);
		data->cheap_i++;
		data->cheap_trgt++;
	}
	while (data->cheap_i != data->a_len)
	{
		rra_sort(data);
		data->cheap_i++;
	}
	data->cheap_i = 0;
	while (data->cheap_trgt != data->b_len)
	{
		rrb_sort(data);
		data->cheap_trgt++;
	}
	data->cheap_trgt = 0;
}

void	apart_a(t_data *data)
{
	while (data->cheap_i != 0)
	{
		ra_sort(data);
		data->cheap_i--;
	}
	while (data->cheap_trgt != data->b_len)
	{
		rrb_sort(data);
		data->cheap_trgt++;
	}
	data->cheap_trgt = 0;
}

void	apart_b(t_data *data)
{
	while (data->cheap_i != data->a_len)
	{
		rra_sort(data);
		data->cheap_i++;
	}
	data->cheap_i = 0;
	while (data->cheap_trgt != 0)
	{
		rb_sort(data);
		data->cheap_trgt--;
	}
}

void	execute_moves_b(t_data *data)
{
	data->mid_a = (data->a_len - 1) / 2;
	data->mid_b = (data->b_len - 1) / 2;
	if (data->cheap_i <= data->mid_a && data->cheap_trgt <= data->mid_b)
		both_above_mid(data);
	else if (data->cheap_i > data->mid_a && data->cheap_trgt > data->mid_b)
		both_below_mid(data);
	else if (data->cheap_i <= data->mid_a && data->cheap_trgt > data->mid_b)
		apart_a(data);
	else
		apart_b(data);
	pb_sort(data);
}
