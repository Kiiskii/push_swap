/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:03:42 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/07 09:20:56 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

long	ft_atol(const char *nptr, t_data *data)
{
	int		isneg;
	long	convert;

	isneg = 1;
	convert = 0;
	while (ft_iswhitespace(*nptr) == 1)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isneg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) == 1)
	{
		convert = convert * 10 + *nptr - '0';
		if (convert > 2147483648)
			break ;
		nptr++;
	}
	convert *= isneg;
	if (convert < INT_MIN || convert > INT_MAX)
		ft_exit(data);
	return (convert);
}

void	validate_nums(t_data *data, size_t curr_index)
{
	size_t	i;

	i = 0;
	while (i < curr_index)
	{
		if (data->stack_a[i] == data->stack_a[curr_index])
			ft_exit(data);
		i++;
	}
}

void	is_valid_input(char **str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!str[i])
		ft_exit(data);
	while (str[i] != 0)
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (str[i][j] == '\0')
			ft_exit(data);
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 1)
				j++;
			else
				ft_exit(data);
		}
		i++;
	}
}

void	array_single_arg(char **argv, t_data *data)
{
	size_t	i;

	i = 0;
	data->str_array = ft_split(argv[0], ' ');
	if (!data->str_array)
		ft_exit(data);
	data->needs_str_array = true;
	while (data->str_array[i] != 0)
		i++;
	data->a_len = i;
	is_valid_input(data->str_array, data);
	data->stack_a = malloc(data->a_len * sizeof(int));
	if (!data->stack_a)
		ft_exit(data);
	data->array_a_mallocd = true;
	i = 0;
	while (data->str_array[i] != 0)
	{
		data->stack_a[i] = ft_atol(data->str_array[i], data);
		validate_nums(data, i);
		i++;
	}
	ft_free(data);
	data->needs_str_array = false;
}

void	array_multi_arg(int argc, char **argv, t_data *data)
{
	size_t	i;

	i = 0;
	data->needs_str_array = false;
	data->a_len = argc - 1;
	is_valid_input(argv, data);
	data->stack_a = malloc(data->a_len * sizeof(int));
	if (!data->stack_a)
		ft_exit(data);
	data->array_a_mallocd = true;
	i = 0;
	while (i < data->a_len)
	{
		data->stack_a[i] = ft_atol(argv[i], data);
		validate_nums(data, i);
		i++;
	}
}
