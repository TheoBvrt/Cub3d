#ifndef CUB3D_HPP
# define CUB3D_HPP

# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef	struct s_game
{
	int		screenWidth;
	int		screenHeight;
	int		exit;
	void	*mlx;
	void	*mlx_win;
}	t_game;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_player;

#endif