#include "../header/cub3d.h"

int	cube3d_init(t_game *game)
{
	game->screenWidth = 1280;
	game->screenHeight = 720;
	game->exit = 0;
	return (0);
}

int main(int argc, char *argv[])
{
	t_game		game;
	t_player	player;

	if (cube3d_init(&game) == 1)
		return (1);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.screenWidth, game.screenHeight, "Cub3D");
	mlx_loop(game.mlx);
	return (0);
}
