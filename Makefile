SRCS		=	main.c

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	./MLX42

LIBFT		=	./libft

HEADERS		=	-I ${LIBMLX}/include/MLX42 -I ${LIBFT}

LIBS		=	${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

GCC = gcc -Wall -Werror -Wextra

NAME = fractol

RM = rm -rf

.c.o:
	${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all: $(LIBFT) $(NAME)

$(LIBFT):
	git submodule update --init
	make -C libft extra
	make -C libft graphics

$(NAME): ${OBJS}
	${GCC} ${OBJS} ${LIBS} -lglfw -L "/Users/cmoran-l/.bre/opt/glfw/lib" ${HEADERS} -o ${NAME}

clean:
	make -C libft fclean
	${RM} ${LIBFT} ${NAME}

fclean: clean
	
re: fclean all

.PHONY: all clean fclean re NAME LIBFT
