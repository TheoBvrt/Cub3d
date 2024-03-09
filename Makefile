NAME = cub3D
SRCS = ./src/main.c ./src/utils.c ./src/utils2.c ./src/utils3.c ./src/init/parsing.c ./src/init/check_tiles.c \
./src/init/check_tiles_after.c ./src/init/get_all_file.c ./src/init/get_info_by_id.c ./src/init/set_colors.c \
./src/init/set_map.c ./src/init/set_textures.c ./src/init/parsing_utils.c ./src/render/draw.c ./src/render/render_update.c \
./src/render/render_utils.c ./src/render/images.c ./src/render/update.c ./src/render/movement.c \
./src/render/update_utils.c ./src/render/movement2.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS =  -g3 -fsanitize=address

all : ${NAME}

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

${NAME} : ${OBJS}
	${MAKE} -C ./libft 
	${MAKE} -C ./mlx
	$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	${RM} ${OBJS} 
	make fclean -C ./Libft
	make clean -Wno-deprecated-declarations -C ./mlx

fclean: clean
	${RM} ${NAME}

re: fclean all
