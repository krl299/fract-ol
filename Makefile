SRCS = main.c

OBJS = ${SRCS:.c=.o}

GCC = gcc -Wall -Werror -Wextra

NAME = fractol

RM = rm -rf

.c.o:
	${GCC} -Imlx -c $< -o ${<:.c=.o}

all: $(LIBFT) $(NAME)

$(LIBFT):
	git submodule update --init
	make -C libft extra

$(NAME): ${OBJS}
	${GCC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	make -C libft fclean
	${RM} ${LIBFT} ${NAME}

fclean: clean
	
re: fclean all

.PHONY: all clean fclean re NAME LIBFT
