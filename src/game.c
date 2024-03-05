#include "../header/cub3d.h"

void clear_image(void *mlx_ptr, void *img_ptr, int width, int height) {
    int bpp, size_line, endian;
    char *img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            *(unsigned int*)(img_data + y * size_line + x * (bpp / 8)) = 0; // Noir
        }
    }
}

void raycasting(t_game *game)
{
	unsigned int buffer[game->screenHeight][game->screenWidth];
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		color;

	int mapX;
	int mapY;

	x = 0;

	for (int y = game->screenHeight / 2; y < game->screenHeight; y++) {
		for (int x = 0; x < game->screenWidth; x++) {
			buffer[y][x] = green;
		}
	}

	for (int y = 0; y < game->screenHeight / 2; y++) {
		for (int x = 0; x < game->screenWidth; x++) {
			buffer[y][x] = blue;
		}
	}

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

		double wallX;
		if (side == 0)
			wallX = game->player.posY + perpWallDist * rayDirY;
		else
			wallX = game->player.posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)64);
		if (side == 0 && rayDirX > 0)
			texX = 64 - texX - 1;
		
		double step = 1.0 * 64 / lineHeight;
		double texPost = (drawStart - game->screenHeight / 2 + lineHeight / 2) * step;

		int bpp;
		int size_line;
		int endian;
		char *texture_data;

		if (game->map.world_map[mapX][mapY] == 1)
		{
			if (side == 0)
			{
				if (rayDirX > 0)
					texture_data = mlx_get_data_addr(game->image.texture, &bpp, &size_line, &endian);
				else
					texture_data = mlx_get_data_addr(game->image.stone, &bpp, &size_line, &endian);
			}
			else
			{
				if (rayDirY > 0)
					texture_data = mlx_get_data_addr(game->image.brick, &bpp, &size_line, &endian);
				else
					texture_data = mlx_get_data_addr(game->image.coloredstone, &bpp, &size_line, &endian);
			}
		}

		for(int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPost & (64 - 1);
			texPost += step;
			unsigned int color = *(int*)(texture_data + (texY * size_line + texX * (bpp / 8)));
			buffer[y][x] = color;
		}
		x++;
	}
	for (int y = 0; y < game->screenHeight; y++) {
		for (int x = 0; x < game->screenWidth; x++) {
			int pos = (y * game->game_img.line_length) + (x * (game->game_img.bits_per_pixel / 8));
				*(unsigned int*)(game->game_img.addr + pos) = buffer[y][x];
		}
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->game_img.img, 0, 0);
	for(int y = 0; y < game->screenHeight; y++) 
		for(int x = 0; x < game->screenWidth; x++)
			buffer[y][x] = 0;
}