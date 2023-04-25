SRCS		=	fractol.c	help_text.c	utils.c	parsers.c	initializers.c	hooks.c

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	./MLX42

LIBFT		=	./libft

HEADERS		=	-I ${LIBMLX}/include/MLX42 -I ${LIBFT} 

LIBS		=	${LIBMLX}/libmlx42.a	${LIBFT}/libft.a

GCC = gcc -Wall -Werror -Wextra

NAME = fractol

RM = rm -rf

.c.o:
	@${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all:	lib	$(NAME)

lib:
	@git submodule update --init
	@make -C libft extra
	@make -C MLX42

$(NAME): ${OBJS}
	@${GCC} ${OBJS} ${LIBS} -lglfw -L "/Users/cmoran-l/.brew/opt/glfw/lib/" ${HEADERS} -o ${NAME}

clean:
	@${RM} ${OBJS}
	@make -C MLX42 fclean
	@make -C libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re NAME LIBFT
