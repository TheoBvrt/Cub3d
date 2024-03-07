#ifndef CUB3D_HPP
# define CUB3D_HPP

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "math.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>

#define WIDTH = 1280
#define HEIGHT = 720

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

enum e_dir
{
	north = 0,
	south = 1,
	west = 2,
	east = 3,
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	*map_path;
	char	**tab;
	//int		world_map[24][24];
	int		height;
	int		width;
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

typedef	struct s_raycasting
{
	int				x;
	int				map_x;
	int				map_y;	
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				bpp;
	int				sl;
	int				end;
	unsigned int	color;
	double			text_pos;
	double			step;
	double			wall_x;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			perp_wall_dist;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	char			*tex_data;
}	t_raycasting;


typedef struct s_image
{
	int		ph;
	int		pw;
	void	*texture;
	void	*stone;
	void	*brick;
	void	*coloredstone;
}	t_image; 

typedef	struct s_game
{
	int				s_w;
	int				s_h;
	int				exit;
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	t_raycasting	ray;
	t_image			image;
	t_player		player;
	t_data			data;
	t_data			game_img;
	t_map			map;
}	t_game;

void	update_render(t_game *game);

//NORME
void	image_loader(t_game *game);
void	image_init_image(t_game *game);
void	raycasting(t_game *game, t_raycasting *ray);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_sky_ground(t_game *game, unsigned int buffer[720][1280]);
void	set_buffer(t_game *game, unsigned int buffer[720][1280]);
void	buffer_feel(t_game *gane, t_raycasting *ray, unsigned int b[720][1280]);
void	set_value(t_game *game, t_raycasting *ray);
int		checker(t_game *game, char *map);
int	get_map_height(t_game *game);
int	get_map_width(t_game *game);
void	set_tab_default(t_game *game);
#endif