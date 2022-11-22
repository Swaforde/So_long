NAME = so_long
SRCS = ./GNL/get_next_line_utils.c ./GNL/get_next_line.c ./src/main.c ./src/map.c ./src/renderer.c ./src/map_format.c \
./src/wall_checker.c ./src/update.c ./src/movement.c ./src/player.c ./src/bot.c

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
	$(CC) $(OBJS) ./Libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -G3 -fsanitize=address

clean:
	${RM} ${OBJS}
	make fclean -C ./libft
	make clean -Wno-deprecated-declarations -C ./mlx

fclean: clean
	${RM} ${NAME}

re: fclean all
