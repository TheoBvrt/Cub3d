/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:59:56 by jmorcom-          #+#    #+#             */
/*   Updated: 2024/03/08 15:45:47 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Libft/includes/libft.h"
# include "Libft/includes/get_next_line.h"
# include "stdlib.h"
# include "stdio.h"
# include	"mlx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include "math.h"
# define WIDTH 1200
# define HEIGHT 800
# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 100
# define T_BOOL unsigned int

typedef unsigned int	t_rgb;

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

typedef enum e_sides
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}t_sides;

enum e_tile {
	VOID = ' ',
	FLOOR = '0',
	WALL = '1',
};

typedef struct texture_path {
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_texture_path;

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_point_d
{
	double	x;
	double	y;
}t_point_d;

typedef struct s_texture {
	t_point			size;
	unsigned int	*pixels;
}	t_texture;

typedef struct s_player2
{
	t_point_d	pos;
	t_point_d	dir_cam;
	t_point_d	cam_plan;
}t_player2;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	int		is_forward;
	int		is_backward;
	int		is_turn_left;
	int		is_turn_right;
	int		side_right;
	int		side_left;
	int		mouse_move;
}	t_player;

typedef struct s_map
{
	t_texture		textures[4];
	char			**tiles;
	t_point 		ply_pos;
	enum e_sides	ply_dir;
	t_point			size;
	t_rgb			floor_color;
	t_rgb			ceiling_color;
}t_map;

typedef struct s_carte
{
	t_player	player;
	t_map		map;
}t_carte;

typedef struct s_raycasting
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
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}	t_image;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
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
	t_data			minimap_img;
	t_map			map;
	t_texture_path	tex_path;
}	t_game;

// UTILS
t_point_d	new_point_d(double x, double y);
t_point		new_point(int x, int y);

// INIT
int			set_colors(char **lines, t_map *map, int first_line);
int			check_tiles(char **lines, t_map *map);
int			check_tiles_after(t_map *map);
int			is_in_charset(char c, char *charset);
char		*get_all_file(char *filename);
char		*get_info_by_id(const char *id, char **lines, int map_first_line);
T_BOOL		color_from_rgb(unsigned char r, \
							unsigned char g, unsigned char b);
void		set_player_cam(t_player *player, char c);
void set_player_spawn(t_carte *carte, int i, int j, char c);
int			set_textures(char **lines, t_carte *carte, int fl, t_game *g);
int			set_tiles(char **lines, t_carte *carte, t_game *game);
int			parse(char *filename, t_carte *carte, t_game *game);

// UTILS
void		free_carte(t_carte *carte);
void		my_exit(char *string, t_carte *carte);
void		split_free(char **split);
void		error_print(char *str);
t_texture	new_text(void *mlx, char *text_path);
int			init_win(t_carte *carte);

// CHECK_ELEMS
int			check_args(int argc, char **argv, t_carte *carte);

// RENDER
void		update_render(t_game *game);
void		image_loader(t_game *game);
void		image_init_image(t_game *game);
void		raycasting(t_game *game, t_raycasting *ray);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_sky_ground(t_game *game, unsigned int buffer[720][1280]);
void		rotation_to(t_game *game, int orientation);
void		set_buffer(t_game *game, unsigned int buffer[720][1280]);
void		buffer_fill(t_game *g, t_raycasting *r, unsigned int b[720][1280]);
void		set_values(t_game *game, t_raycasting *ray);
void		hooks(t_game *game);
void		forward(t_game *game);
void		backward(t_game *game);
void		side_to_left(t_game *g);
void		side_to_right(t_game *g);
void		turn_left(t_game *game);
void		turn_right(t_game *game);
void		destroy_images(t_game *game);
void		delock(t_game *game);
void		lock(t_game *game);
int			kill_game(t_game *game);

#endif //CUB3D_HEADER_H
