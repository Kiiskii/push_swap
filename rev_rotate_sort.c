/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:59:30 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/03 10:13:31 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_sort(t_data *data)
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
	if (!data->double_rotate)
		ft_printf("rra\n");
}

void	rrb_sort(t_data *data)
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
	if (!data->double_rotate)
		ft_printf("rrb\n");
}

void	rrr_sort(t_data *data)
{
	data->double_rotate = true;
	rra_sort(data);
	rrb_sort(data);
	data->double_rotate = false;
	ft_printf("rrr\n");
}
