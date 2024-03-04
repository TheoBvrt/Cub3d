#include "../header/cub3d.h"

int	cube3d_init(t_game *game)
{
	void	*texture;

	int tmp[8][8]=
	{
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,1,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1},
	};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            game->map.world_map[i][j] = tmp[i][j];
        }
    }
	game->screenWidth = 1280;
	game->screenHeight = 720;
	game->exit = 0;

	game->player.posX = 5;
	game->player.posY = 4;

	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	return (0);
}

void	image_load(t_game *game)
{
	game->image.texture = mlx_xpm_file_to_image(game->mlx, "./images/north.xpm", &game->image.pw, &game->image.ph);
}

void	drawline(int xOrigin, int yStart, int yEnd, t_game *game, int color) {
	int x;
	int y;

	x = xOrigin;
	y = yStart;
	while (y <= yEnd)
	{
		my_mlx_pixel_put(&game->data, x, y, color);
		y ++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	//ft_printf("test");
}

void	clear_win(t_game *game, t_data *img)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y <= game->screenHeight)
	{
		while (x <= game->screenWidth)
		{
			my_mlx_pixel_put(&game->data, x, y, 0xFFFFFF);
			x ++;
		}
		x = 0;
		y++;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 126)
		game->player.isForward = 0;
	if (keycode == 125)
		game->player.isBackward = 0;
	if (keycode == 124)
		game->player.isTurnLeft = 0;
	if (keycode == 123)
		game->player.isTurnRight = 0;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 126)
		game->player.isForward = 1;
	if (keycode == 125)
		game->player.isBackward = 1;
	if (keycode == 124)
		game->player.isTurnLeft = 1;
	if (keycode == 123)
		game->player.isTurnRight = 1;
	return (0);
}


int	update(t_game *game)
{
	if (game->player.isForward == 0)
	{
		if(game->map.world_map[(int)(game->player.posX + game->player.dirX * game->player.moveSpeed)][(int)(game->player.posY)] == 0)
			game->player.posX += game->player.dirX * game->player.moveSpeed;
		if(game->map.world_map[(int)(game->player.posX)][(int)(game->player.posY + game->player.dirY * game->player.moveSpeed)] == 0)
			game->player.posY += game->player.dirY * game->player.moveSpeed;
	}
	if (game->player.isBackward == 0)
	{
		if(game->map.world_map[(int)(game->player.posX - game->player.dirX * game->player.moveSpeed)][(int)(game->player.posY)] == 0)
			game->player.posX -= game->player.dirX * game->player.moveSpeed;
		if(game->map.world_map[(int)(game->player.posX)][(int)(game->player.posY - game->player.dirY * game->player.moveSpeed)] == 0)
			game->player.posY -= game->player.dirY * game->player.moveSpeed;
	}
	if (game->player.isTurnLeft == 0)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->player.moveSpeed) - game->player.dirY * sin(-game->player.moveSpeed);
		game->player.dirY  = oldDirX * sin(-game->player.moveSpeed) + game->player.dirY * cos(-game->player.moveSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->player.moveSpeed) - game->player.planeY * sin(-game->player.moveSpeed);
		game->player.planeY = oldPlaneX * sin(-game->player.moveSpeed) + game->player.planeY * cos(-game->player.moveSpeed);
	}
	if (game->player.isTurnRight == 0)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(game->player.moveSpeed) - game->player.dirY * sin(game->player.moveSpeed);
		game->player.dirY  = oldDirX * sin(game->player.moveSpeed) + game->player.dirY * cos(game->player.moveSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(game->player.moveSpeed) - game->player.planeY * sin(game->player.moveSpeed);
		game->player.planeY = oldPlaneX * sin(game->player.moveSpeed) + game->player.planeY * cos(game->player.moveSpeed);
	}
	//raycasting(game);
	//clear_win(game, &game->data);
	return (0);
}

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L<<0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L<<1, key_release, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
}

int main(int argc, char *argv[])
{
		t_game		game;

		if (cube3d_init(&game) == 1)
			return (1);
		game.player.isForward = 1;
		game.player.isBackward = 1;
		game.player.isTurnLeft = 1;
		game.player.isTurnRight = 1;
		game.player.moveSpeed = 0.04;
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, game.screenWidth, game.screenHeight, "cub3d");
		game.data.img = mlx_new_image(game.mlx, game.screenWidth, game.screenHeight);
		game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bits_per_pixel, &game.data.line_length,
									&game.data.endian);
		//image_load(&game);
		//raycasting(&game);
		//my_mlx_pixel_put(&game.data, 50, 50, red);z
		//draw_ground(&game);
		//clear_win(&game, &game.data);
		hooks(&game);
		return (0);
}
