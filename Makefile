NAME = so_long
SRCS = ./GNL/get_next_line_utils.c ./GNL/get_next_line.c ./src/main.c ./src/mlx_utils.c ./src/map.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o : %.c
	$(CC) -Imlx -c $< -o $@

${NAME} : ${OBJS}
	${MAKE} bonus -C ./libft 
	${MAKE} -C ./mlx
	$(CC) $(OBJS) ./Libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJS}
	make fclean -C ./libft
	make clean -Wno-deprecated-declarations -C ./mlx

fclean: clean
	${RM} ${NAME}

re: fclean all