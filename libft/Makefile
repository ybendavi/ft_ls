# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 18:24:15 by ybendavi          #+#    #+#              #
#    Updated: 2021/10/19 13:27:13 by ybendavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRCS = \
	ft_isalnum.c \
	ft_memccpy.c \
	ft_memset.c \
	ft_strlcpy.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_substr.c \
	ft_atoi.c \
	ft_isascii.c \
	ft_memcmp.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_strjoin.c \
	ft_strnstr.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_isprint.c \
	ft_memmove.c \
	ft_strlcat.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstadd_back.c \
	ft_lstlast.c \
	ft_lstsize.c \
	ft_lstadd_front.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_printf.c \
	analize_format.c \
	format_flag_handler.c \
	ft_itoa_base.c \
	type_flag_handler.c \
	int_point.c \
	format_flags_assets.c \
	format_flags_assets_p2.c \
	str_format_flag.c \
	set_flags.c \
	p_format_flags.c

OBJS = ${SRCS:.c=.o}

$(NAME):
	${CC} ${FLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: 	$(NAME)	

clean:
	${RM} ${OBJS} ${BNOBJS}

fclean: clean
		$(RM) ${NAME}

re: fclean all

.PHONY: clean all fclean re
