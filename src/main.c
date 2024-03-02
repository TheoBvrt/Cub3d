#include "../header/cub3d.h"

int	cube3d_init(t_game *game)
{
	int tmp[24][24]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            game->map.world_map[i][j] = tmp[i][j];
        }
    }
	game->screenWidth = 1280;
	game->screenHeight = 720;
	game->exit = 0;

	game->player.posX = 4;
	game->player.posY = 4;
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	return (0);
}

void	drawline(int xOrigin, int yStart, int yEnd, t_game *game) {
	int x;
	int y;

	x = xOrigin;
	y = yStart;
	while (y <= yEnd)
	{
		my_mlx_pixel_put(&game->data, x, y, 0xFFFFFF);
		y ++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

	int	test(int keycode, t_game *game)
	{
		if (keycode == 126) {
			game->player.posX += game->player.dirX * 0.2;
			game->player.posY += game->player.dirY * 0.2;
		}
		if (keycode == 125) {
			game->player.posX -= game->player.dirX * 0.2;
			game->player.posY -= game->player.dirY * 0.2;
		}
		if (keycode == 124) {
			double oldDirX = game->player.dirX;
			game->player.dirX = game->player.dirX * cos(-0.2) - game->player.dirY * sin(-0.2);
			game->player.dirY  = oldDirX * sin(-0.2) + game->player.dirY * cos(-0.2);
			double oldPlaneX = game->player.planeX;
			game->player.planeX = game->player.planeX * cos(-0.2) - game->player.planeY * sin(-0.2);
			game->player.planeY = oldPlaneX * sin(-0.2) + game->player.planeY * cos(-0.2);
		}
		if (keycode == 123) {
			double oldDirX = game->player.dirX;
			game->player.dirX = game->player.dirX * cos(0.2) - game->player.dirY * sin(0.2);
			game->player.dirY  = oldDirX * sin(0.2) + game->player.dirY * cos(0.2);
			double oldPlaneX = game->player.planeX;
			game->player.planeX = game->player.planeX * cos(0.2) - game->player.planeY * sin(0.2);
			game->player.planeY = oldPlaneX * sin(0.2) + game->player.planeY * cos(0.2);
		}
		clear_win(game, &game->data);
		raycasting(game);
		return (0);
	}

void	hooks(t_game *game)
{
	mlx_key_hook(game->mlx_win, &test, game);
	mlx_loop(game->mlx);
}

int main(int argc, char *argv[])
{
		t_game		game;
		t_data		img;

		game.data = img;
		if (cube3d_init(&game) == 1)
			return (1);
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, game.screenWidth, game.screenHeight, "cub3d");
		game.data.img = mlx_new_image(game.mlx, game.screenWidth, game.screenHeight);
		game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bits_per_pixel, &game.data.line_length,
									&game.data.endian);
		raycasting(&game);
		hooks(&game);
		return (0);
}
