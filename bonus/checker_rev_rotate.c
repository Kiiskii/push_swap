/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:40:34 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/06 14:27:51 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_sort_checker(t_data *data)
{
	int		temp;
	size_t	i;

	i = data->a_len - 1;
	temp = data->stack_a[i];
	while (i > 0)
	{
		data->stack_a[i] = data->stack_a[i - 1];
		i--;
	}
	data->stack_a[i] = temp;
}

void	rrb_sort_checker(t_data *data)
{
	int		temp;
	size_t	i;

	i = data->b_len - 1;
	temp = data->stack_b[i];
	while (i > 0)
	{
		data->stack_b[i] = data->stack_b[i - 1];
		i--;
	}
	data->stack_b[i] = temp;
}

void	rrr_sort_checker(t_data *data)
{
	data->double_rotate = true;
	rra_sort_checker(data);
	rrb_sort_checker(data);
	data->double_rotate = false;
}
