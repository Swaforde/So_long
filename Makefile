NAME = so_long
SRCS = ./GNL/get_next_line_utils.c ./GNL/get_next_line.c ./src/main.c ./src/map.c ./src/map_format.c \
./src/wall_checker.c ./src/update.c ./src/movement.c ./src/player.c ./src/backtracking.c ./src/utils.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o : %.c
	$(CC) -Imlx -c $< -o $@

${NAME} : ${OBJS}
	${MAKE} bonus -C ./Libft 
	${MAKE} -C ./mlx
	$(CC) $(OBJS) $(CFLAGS) ./Libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	${RM} ${OBJS}
	make fclean -C ./Libft
	make clean -Wno-deprecated-declarations -C ./mlx

fclean: clean
	${RM} ${NAME}

re: fclean all
