#include "../header/cub3d.h"

void draw_ground(t_game *game)
{
	int x;
	int y;

	y = game->screenHeight / 2;
	x = 0;
	while (y < game->screenHeight)
	{
		while (x < game->screenWidth) {
			my_mlx_pixel_put(&game->game_img, x, y, green);
			x++;
		}
		x = 0;
		y ++;
	}
}

void	draw_sky(t_game *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < game->screenHeight / 2)
	{
		while (x < game->screenWidth) {
			my_mlx_pixel_put(&game->data, x, y, black);
			x++;
		}
		x = 0;
		y ++;
	}
}