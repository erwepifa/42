# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 12:50:09 by erwepifa          #+#    #+#              #
#    Updated: 2019/01/28 14:44:18 by erwepifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = check_str.c \
	   insert.c \
	   main.c \
	   solve.c \
	   check.c \
	   error.c \
	   free.c \
	   map.c \
	   pieces.c \
	   test.c

FLAGS = -Wall \
	   -Werror \
	   -Wextra

OBJS = $(SRCS:.c=.o)

HEADER = ./
	
all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $^ -L. libft/libft.a

./%.o: ./%.c
	@gcc $(FLAGS) -c $^ -I $(HEADER) -I ./libft/

clean:
	@/bin/rm -f $(OBJS)
	@make -C libft clean
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean re fclean libft
