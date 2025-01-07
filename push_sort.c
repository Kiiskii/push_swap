/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:54:39 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/07 09:26:22 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_sort(t_data *data)
{
	if (data->a_len > 0)
	{
		if (data->b_len > 0)
			ft_memmove(&data->stack_b[1], &data->stack_b[0], data->b_len * 4);
		data->stack_b[0] = data->stack_a[0];
		data->b_len++;
		data->a_len--;
		ft_memmove(&data->stack_a[0], &data->stack_a[1], data->a_len * 4);
		ft_printf("pb\n");
	}
}

void	pa_sort(t_data *data)
{
	if (data->b_len > 0)
	{
		if (data->a_len > 0)
			ft_memmove(&data->stack_a[1], &data->stack_a[0], data->a_len * 4);
		data->stack_a[0] = data->stack_b[0];
		data->a_len++;
		data->b_len--;
		ft_memmove(&data->stack_b[0], &data->stack_b[1], data->b_len * 4);
		ft_printf("pa\n");
	}
}

void	sa_sort(t_data *data)
{
	int	temp;

	temp = data->stack_a[0];
	data->stack_a[0] = data->stack_a[1];
	data->stack_a[1] = temp;
	ft_printf("sa\n");
}
