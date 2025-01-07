/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:43:56 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/06 15:13:20 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = &(t_data){NULL, .needs_str_array = false, .array_a_mallocd = false,
		.array_b_mallocd = false};
	if (argc < 2)
		return (0);
	if (argc == 2)
		array_single_arg(&argv[1], data);
	else
		array_multi_arg(argc, &argv[1], data);
	data->stack_b = malloc(data->a_len * sizeof(int));
	if (!data->stack_b)
		ft_exit(data);
	data->array_b_mallocd = true;
	if (!is_sorted(data))
		sort_root(data);
	free(data->stack_a);
	free(data->stack_b);
	return (0);
}
