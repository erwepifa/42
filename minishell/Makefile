# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 13:47:27 by erwepifa          #+#    #+#              #
#    Updated: 2019/07/13 21:37:23 by erwepifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES) $(FLAGS)

FLAGS = -Wall -Wextra -Werror -g

NAME = minishell

INCLUDES = -I include/ -I libft/includes -I

HEADERS = minishell.h\

LIBFT = libft/libft.a

SRCS = 	main.c \
		env.c \
		malloc.c \
		execute.c \
		minishell.c \
		options.c \
		echo.c \
		access.c \
		check_cd.c \
		cd.c \
		free_tab.c \



OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(LIBFT) $(HEADERS) $(PRINTF)
	@printf "\033[032mMINISHELL : Object files Created\033[0m\n"
	@$(CC) $(NCURSES) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)
	@printf "\033[032mMINISHELL : MINISHELL Created\033[0m\n"

$(LIBFT) :
	@make -C libft/

clean :
	@rm -f $(OBJS)
	@echo "\033[32mMINISHELL : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[32mMINISHELL : MINISHELL Removed\033[0m"

up : all clean

re : fclean all
