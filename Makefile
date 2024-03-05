NAME = cub3D
SRCS = ./src/main.c ./src/render/render_update.c ./src/parsing/images.c ./src/render/draw.c ./src/render/render_utils.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS =  -g3 -fsanitize=address

all : ${NAME}

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

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
