# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 20:37:02 by erwepifa          #+#    #+#              #
#    Updated: 2020/10/21 20:37:20 by erwepifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	*.c
OBJ		=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	libftprintf.a

$(NAME):
				$(MAKE) -C libft
				$(CC) -c $(CFLAGS) $(SRCS)
				ar rcs $(NAME) $(OBJ) libft/*.o

all:			$(NAME)

clean:
				rm -rf $(OBJ)
				$(MAKE) -C libft fclean

fclean:			clean
				rm -rf $(NAME)

re:				fclean all