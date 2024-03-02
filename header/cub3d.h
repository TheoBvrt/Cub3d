#ifndef CUB3D_HPP
# define CUB3D_HPP

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "math.h"

typedef struct s_map
{
	int	world_map[24][24];
}	t_map;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_player;

typedef	struct s_game
{
	int			screenWidth;
	int			screenHeight;
	int			exit;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	t_player	player;
	t_map		map;
}	t_game;

void	raycasting(t_game *game);
void	drawline(int xOrigin, int yStart, int yEnd, t_game *game);
void	draw_ground(t_game *game);
void	draw_sky(t_game *game);

#endif