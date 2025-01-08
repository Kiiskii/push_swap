# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akiiski <akiiski@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 14:07:36 by akiiski           #+#    #+#              #
#    Updated: 2025/01/08 14:30:16 by akiiski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -I libft/

SRCS = 	push_swap.c parsing.c mem_managment.c sort.c push_sort.c \
		rotate_sort.c rev_rotate_sort.c calc_cheapest.c execute_moves_b.c \
		execute_moves_a.c utils.c

BSRCS = bonus/checker.c bonus/checker_push_swap.c bonus/checker_rev_rotate.c \
		bonus/checker_rotate.c parsing.c mem_managment.c

NAME = push_swap

BONUS = checker

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BOBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFT) -o $(BONUS)

clean:
	rm -f *.o
	rm -f bonus/*.o
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS) $(LIBFT)

re:	fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g
