#include "../header/cub3d.h"

void raycasting(t_game *game)
{
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		color;

	int mapX;
	int mapY;

	x = 0;
	while (x < game->screenWidth)
	{
		cameraX = 2 * x / (double)game->screenWidth - 1;
		double rayDirX = game->player.dirX + game->player.planeX * cameraX;
		double rayDirY = game->player.dirY + game->player.planeY * cameraX;

		int mapX = (int)game->player.posX;
		int mapY = (int)game->player.posY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double sideDistX;
	    double sideDistY;

	  	double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side; 

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player.posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player.posY) * deltaDistY;
		}
		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if(game->map.world_map[mapX][mapY] > 0) hit = 1;
		}

		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
      	else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(game->screenHeight / perpWallDist);

		int drawStart = -lineHeight / 2 + game->screenHeight / 2;
     	if(drawStart < 0) drawStart = 0;
      	int drawEnd = lineHeight / 2 + game->screenHeight / 2;
      	if(drawEnd >= game->screenHeight) drawEnd = game->screenHeight - 1;


		if (game->map.world_map[mapX][mapY] == 1)
		{
			if (side == 0)
			{
				if (rayDirX > 0)
					color = red; //nord
				else
					color = orange; //sud
			}
			else
			{
				if (rayDirY > 0)
					color = white; //ouest
				else
					color = purple; //est
			}
		}
		drawline(x, drawStart, drawEnd, game, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->data.img, 0, 0);
}