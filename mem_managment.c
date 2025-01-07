/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:00:18 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/06 12:34:16 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->a_len)
	{
		free(data->str_array[i]);
		i++;
	}
	free(data->str_array);
}

void	ft_exit(t_data *data)
{
	if (data->needs_str_array == true)
		ft_free(data);
	if (data->array_a_mallocd == true)
		free(data->stack_a);
	if (data->array_b_mallocd == true)
		free(data->stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
