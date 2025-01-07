/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:55:23 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/07 12:16:09 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sorted_checker(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->a_len - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	check_moves(char *line, t_data *data)
{
	if (ft_strncmp("pb\n", line, 3) == 0)
		pb_sort_checker(data);
	else if (ft_strncmp("pa\n", line, 3) == 0)
		pa_sort_checker(data);
	else if (ft_strncmp("sa\n", line, 3) == 0)
		sa_sort_checker(data);
	else if (ft_strncmp("rb\n", line, 3) == 0)
		rb_sort_checker(data);
	else if (ft_strncmp("ra\n", line, 3) == 0)
		ra_sort_checker(data);
	else if (ft_strncmp("rr\n", line, 3) == 0)
		rr_sort_checker(data);
	else if (ft_strncmp("rrb\n", line, 4) == 0)
		rrb_sort_checker(data);
	else if (ft_strncmp("rra\n", line, 4) == 0)
		rra_sort_checker(data);
	else if (ft_strncmp("rrr\n", line, 4) == 0)
		rrr_sort_checker(data);
	else
	{
		free(line);
		ft_exit(data);
	}
}

void	read_line(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		check_moves(line, data);
		free(line);
	}
	free(line);
}

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
	read_line(data);
	if (!is_sorted_checker(data) || data->b_len != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(data->stack_a);
	free(data->stack_b);
	return (0);
}
