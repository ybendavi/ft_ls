LIBFT = ./libft
NAME = ft_ls
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
SRCS = main.c dir_content_handler.c

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		$(MAKE) -C ${LIBFT}
		$(CC) $(FLAGS) $(OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

clean:
	$(MAKE) clean -C ${LIBFT}
	${RM} ${OBJS}

fclean: 	
		$(MAKE) fclean -C ${LIBFT}
		$(RM) ${NAME}
		${RM} ${OBJS}

re: fclean all
	$(MAKE) re -C ${LIBFT}

.PHONY: clean all fclean re