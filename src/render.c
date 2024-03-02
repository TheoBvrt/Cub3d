#include "../header/cub3d.h"

void draw_ground(t_game *game)
{
	int x;
	int y;

	y = 400;
	x = 0;
	while (y <= game->screenHeight)
	{
		while (x <= game->screenWidth) {
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x09A61F);
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
	while (y <= game->screenHeight / 2)
	{
		while (x <= game->screenWidth) {
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x0989A6);
			x++;
		}
		x = 0;
		y ++;
	}
}