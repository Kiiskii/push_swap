/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:23:03 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/07 15:05:54 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_sort(t_data *data)
{
	int		temp;
	size_t	i;

	i = 0;
	if (data->a_len > 1)
	{
		temp = data->stack_a[i];
		while (i < data->a_len - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = temp;
	}
	if (!data->double_rotate)
		ft_printf("ra\n");
}

void	rb_sort(t_data *data)
{
	int		temp;
	size_t	i;

	i = 0;
	if (data->b_len > 1)
	{
		temp = data->stack_b[i];
		while (i < data->b_len - 1)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = temp;
	}
	if (!data->double_rotate)
		ft_printf("rb\n");
}

void	rr_sort(t_data *data)
{
	data->double_rotate = true;
	ra_sort(data);
	rb_sort(data);
	data->double_rotate = false;
	ft_printf("rr\n");
}
