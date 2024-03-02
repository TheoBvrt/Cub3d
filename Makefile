NAME = cub3D
SRCS = ./src/main.c ./src/game.c ./src/render.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all : ${NAME}

%.o : %.c
	$(CC) -Imlx -c $< -o $@

${NAME} : ${OBJS}
	${MAKE} bonus -C ./libft 
	${MAKE} -C ./mlx
	$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	${RM} ${OBJS}
	make fclean -C ./Libft
	make clean -Wno-deprecated-declarations -C ./mlx

fclean: clean
	${RM} ${NAME}

re: fclean all
