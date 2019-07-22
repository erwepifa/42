# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 19:08:17 by tescriva          #+#    #+#              #
#    Updated: 2019/05/29 15:03:58 by erwepifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = gcc $(INCLUDES) $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = libft.a

HEADERS = ./includes/libft.h

INCLUDES = -I includes/

SRCS =	int/ft_atoi.c \
		int/ft_intlen.c \
		int/ft_intlen_base.c \
		int/ft_itoa_base.c \
		int/ft_itoa.c \
		int/ft_putnbr.c \
		int/ft_strlen.c \
		int/ft_strwlen.c \
		int/ft_pf_itoa_base.c \
		int/ft_pf_itoa.c \
		int/ft_intlen_unsigned.c \
		int/ft_charlen.c \
		char/ft_chrstr.c \
		char/ft_putwchar.c \
		char/ft_isalnum.c \
		char/ft_isalpha.c \
		char/ft_isascii.c \
		char/ft_isdigit.c \
		char/ft_isprint.c \
		char/ft_putchar.c \
		char/ft_tolower.c \
		char/ft_toupper.c \
		list/ft_lstadd.c \
		list/ft_lstdel.c \
		list/ft_lstdelone.c \
		list/ft_lstiter.c \
		list/ft_lstmap.c \
		list/ft_lstnew.c \
		mem/ft_memalloc.c \
		mem/ft_memccpy.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memdel.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		mem/ft_bzero.c \
		mem/ft_strdup.c \
		mem/ft_strndup.c \
		mem/ft_strcdup.c \
		fd/ft_putchar_fd.c \
		fd/ft_putendl_fd.c \
		fd/ft_putnbr_fd.c \
		fd/ft_putstr_fd.c \
		fd/get_next_line.c \
		fd/ft_read_data.c \
		string/ft_strequ.c \
		string/ft_striter.c \
		string/ft_strjoin.c \
		string/ft_strjoinfree.c \
		string/ft_strlcat.c\
		string/ft_strmap.c \
		string/ft_strmapi.c \
		string/ft_strncat.c \
		string/ft_strncmp.c \
		string/ft_strncpy.c \
		string/ft_strnequ.c \
		string/ft_strnew.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_strsplit.c \
		string/ft_strstr.c \
		string/ft_strsub.c \
		string/ft_strtrim.c \
		string/ft_putstr.c \
		string/ft_strcat.c \
		string/ft_strchr.c \
		string/ft_strclr.c \
		string/ft_strcmp.c \
		string/ft_strcpy.c \
		string/ft_strdel.c \
		string/ft_putendl.c \
		string/ft_strrev.c \
		string/ft_strnrev.c \
		ft_pf/arg/percent.c \
		ft_pf/arg/char.c \
		ft_pf/arg/ft_flag_for_arg.c \
		ft_pf/arg/int.c \
		ft_pf/arg/unsigned.c \
		ft_pf/utils/ft_putwchar.c\
		ft_pf/utils/ft_tools_1.c\
		ft_pf/utils/ft_tools_2.c \
		ft_pf/ft_arg.c \
		ft_pf/ft_printf.c\
		ft_pf/ft_struct.c \
		ft_pf/print.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(HEADERS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "\033[032mLibft : Object files Created\033[0m"
		@echo "\033[032mLibft : Libft.a Created\033[0m"

clean :
	@rm -f $(OBJS)
	@echo "\033[32mLibft : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[32mLibft : Libft.a Removed\033[0m"

up : all clean

re : fclean all

.SILENT: $(OBJS)
