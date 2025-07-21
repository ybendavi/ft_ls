LIBFT = ./libft
NAME = ft_ls
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRCS = *.c

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		$(MAKE) -C ${LIBFT}
		$(CC) $(OBJS) -Llibft -lft -Wall -Wextra -Werror -o $(NAME)

all: 	$(NAME)	

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
