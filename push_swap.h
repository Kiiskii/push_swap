/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:33 by akiiski           #+#    #+#             */
/*   Updated: 2025/01/07 14:33:20 by akiiski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <stdbool.h>

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int		max;
	int		min;
	size_t	max_i;
	size_t	cheap_i;
	size_t	cheap_cost;
	size_t	cheap_trgt;
	size_t	a_len;
	size_t	b_len;
	size_t	mid_a;
	size_t	mid_b;
	char	**str_array;
	bool	needs_str_array;
	bool	array_a_mallocd;
	bool	array_b_mallocd;
	bool	double_rotate;
}		t_data;

// Parsing
void	array_multi_arg(int argc, char **argv, t_data *data);
void	array_single_arg(char **argv, t_data *data);
void	check_duplicates(t_data *data, size_t curr_index);
void	is_valid_input(char **str, t_data *data);
long	ft_atol(const char *nptr, t_data *data);

// Memory managment
void	ft_exit(t_data *data);
void	ft_free(t_data *data);

// Sorting

bool	is_sorted(t_data *data);
void	sort_three(t_data *data);
void	sort_under_five(t_data *data);
void	sort_root(t_data *data);
void	sa_sort(t_data *data);
void	pb_sort(t_data *data);
void	pa_sort(t_data *data);
void	ra_sort(t_data *data);
void	rra_sort(t_data *data);
void	rb_sort(t_data *data);
void	rrb_sort(t_data *data);
void	rr_sort(t_data *data);
void	rrr_sort(t_data *data);
bool	is_max_value(int curr_index, int *array, size_t len);
bool	is_min_value(int curr_index, int *array, size_t len);

// Calculating operations

void	calc_cheapest(t_data *data);
void	find_max_min(t_data *data, int *array, size_t len);
size_t	find_target_b(int curr_i, t_data *data);
size_t	find_target_a(int curr_i, t_data *data);
size_t	count_cost(size_t i, size_t target_i, t_data *data);

// Executing moves

void	execute_moves_b(t_data *data);
void	both_above_mid(t_data *data);
void	both_below_mid(t_data *data);
void	execute_moves_a(t_data *data);
void	move_smallest_top(t_data *data);
void	apart_a(t_data *data);
void	apart_b(t_data *data);

// Bonus

void	check_moves(char *line, t_data *data);
void	read_line(t_data *data);
void	pb_sort_checker(t_data *data);
void	pa_sort_checker(t_data *data);
void	sa_sort_checker(t_data *data);
void	sb_sort_checker(t_data *data);
void	ss_sort_checker(t_data *data);
void	ra_sort_checker(t_data *data);
void	rb_sort_checker(t_data *data);
void	rr_sort_checker(t_data *data);
void	rra_sort_checker(t_data *data);
void	rrb_sort_checker(t_data *data);
void	rrr_sort_checker(t_data *data);
void	free_line_exit(char *line, t_data *data);
bool	is_sorted_checker(t_data *data);

#endif
