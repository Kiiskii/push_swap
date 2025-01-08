/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:37:44 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/07 14:22:03 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_sort_checker(t_data *data)
{
	if (data->a_len > 0)
	{
		if (data->b_len > 0)
			ft_memmove(&data->stack_b[1], &data->stack_b[0], data->b_len * 4);
		data->stack_b[0] = data->stack_a[0];
		data->b_len++;
		data->a_len--;
		ft_memmove(&data->stack_a[0], &data->stack_a[1], data->a_len * 4);
	}
}

void	pa_sort_checker(t_data *data)
{
	if (data->b_len > 0)
	{
		if (data->a_len > 0)
			ft_memmove(&data->stack_a[1], &data->stack_a[0], data->a_len * 4);
		data->stack_a[0] = data->stack_b[0];
		data->a_len++;
		data->b_len--;
		ft_memmove(&data->stack_b[0], &data->stack_b[1], data->b_len * 4);
	}
}

void	sa_sort_checker(t_data *data)
{
	int	temp;

	if (data->a_len > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
	}
}

void	sb_sort_checker(t_data *data)
{
	int	temp;

	if (data->b_len > 1)
	{
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
	}
}

void	ss_sort_checker(t_data *data)
{
	sa_sort_checker(data);
	sb_sort_checker(data);
}
