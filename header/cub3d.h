#ifndef CUB3D_HPP
# define CUB3D_HPP

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "math.h"

enum e_color
{
	red = 0xe81010,
	orange = 0xe89210,
	purple = 0x9910e8,
	yellow = 0xe81f10,
	white = 0xffffff,
	green = 0x2ea100,
	blue = 0x004f6e,
	black = 0x000000
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	double	moveSpeed;
	int		isForward;
	int		isBackward;
	int		isTurnLeft;
	int		isTurnRight;
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
	t_data		data;
	t_map		map;
}	t_game;

void	raycasting(t_game *game);
void	drawline(int xOrigin, int yStart, int yEnd, t_game *game, int color);
void	draw_ground(t_game *game);
void	draw_sky(t_game *game);
void	clear_win(t_game *game, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif