# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2019/07/22 20:54:06 by erwepifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES) $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = ft_ls

INCLUDES = -I include/ -I libft/includes/ -I

HEADERS = ./include/ft_ls.h\

LIBFT = libft/libft.a

SRCS = 	main.c \
		folder.c \
		parsing_flag.c \
		display.c \
		list/ft_create_node.c \
		list/ft_sort_node.c \
		list/ft_delete_node.c \
		list/ft_print_list.c \
		print_info.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) $(LIBFT) $(OBJS) $(HEADERS)
	@printf "\033[032mFT_LS : Object files Created\033[0m\n"
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "\033[032mFT_LS : FT_LS Created\033[0m\n"

$(LIBFT) :
	@make -C libft/

clean :
	@rm -f $(OBJS)
	@make clean -C libft/
	@echo "\033[32mFT_LS : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "\033[32mFT_LS : FT_LS Removed\033[0m"

up : all clean

re : fclean all
