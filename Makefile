# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johannaaoyama <johannaaoyama@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/14 18:55:53 by johannaaoya       #+#    #+#              #
#    Updated: 2026/11/14 18:55:59 by johannaaoya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = assign_index.c \
		adaptive.c \
		dll.c \
              selection_sort.c \
              push_ops.c \
              swap_ops.c \
              rotate_ops.c \
              reverse_ops.c \
              parse.c \
              validation.c \
              disorder.c \
              helper_functions.c \
              sort_medium.c \
              benchmark.c \
		radix_sort.c \
              push_swap.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
