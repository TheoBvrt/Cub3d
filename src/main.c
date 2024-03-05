#include "./../cub3d.h"

int	cube3d_init(t_game *game)
{
	void	*texture;

	int tmp[8][8]=
	{
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,1},
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
	game->s_w = 1280;
	game->s_h = 720;
	game->exit = 0;

	game->player.posX = 5;
	game->player.posY = 4;

	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	return (0);
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
	mlx_clear_window(game->mlx, game->mlx_win);
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
	raycasting(game, &game->ray);
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
		t_game			game;
		t_raycasting	ray;
		if (cube3d_init(&game) == 1)
			return (1);
		game.player.isForward = 1;
		game.player.isBackward = 1;
		game.player.isTurnLeft = 1;
		game.player.isTurnRight = 1;
		game.player.moveSpeed = 0.04;
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, game.s_w, game.s_h, "cub3d");
		image_loader(&game);
		image_init_image(&game);
		raycasting(&game, &ray);
		mlx_put_image_to_window(game.mlx, game.mlx_win, game.game_img.img, 0, 0);
		mlx_put_image_to_window(game.mlx, game.mlx_win, game.data.img, 0, 0);
		hooks(&game);
		return (0);
}
