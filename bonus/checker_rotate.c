/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:39:13 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/06 14:28:10 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_sort_checker(t_data *data)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = data->stack_a[i];
	while (i < data->a_len - 1)
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[i] = temp;
}

void	rb_sort_checker(t_data *data)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = data->stack_b[i];
	while (i < data->b_len - 1)
	{
		data->stack_b[i] = data->stack_b[i + 1];
		i++;
	}
	data->stack_b[i] = temp;
}

void	rr_sort_checker(t_data *data)
{
	data->double_rotate = true;
	ra_sort_checker(data);
	rb_sort_checker(data);
	data->double_rotate = false;
}
