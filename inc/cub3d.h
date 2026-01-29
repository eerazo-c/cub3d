/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:04:57 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/29 17:32:04 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H 
# define CUB3D_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

//keyboard
# define ON_KEYPRESS 2
# define ON_DESTROY 17
# define ON_KEYRELEASE 3
# define ESC 65307

# define K_LEFT 65361
# define K_RIGHT 65363

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

# define WIDTH	1080
# define HEIGHT	1020

typedef struct s_img_d
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		size_l;
}	t_img_d;

typedef struct s_player
{
	double	speed;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}					t_player;

typedef struct s_cardinal
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}					t_cardinal;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	rotateleft;
	int	rotateright;
}	t_keys;

typedef struct s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	t_keys			keys;
	int				floor_color;
	int				floor_exist;
	int				ceiling_exist;
	int				ceiling_color;
	int				map_started;
	t_player		player;
	t_img_d			*imgs;
	t_cardinal		cardinal;
	unsigned int	map_width;
	unsigned int	map_height;
}	t_map;

//PROTOTIPO_FUNCIONES

//main
void	check_arg(int argc, char **argv);

//draw_map
int		get_texture_wall(t_map *game, t_raycast *ray, t_img_d *text);
void	draw_ceiling(t_map *game, int x, int draw_start);
void	draw_wall(t_map *game, t_raycast *ray, int x, t_img_d *texture, int tex_x);
void	draw_floor(t_map *game, int x, int draw_end);
void	draw_vertical_line(t_map *game, t_raycast *ray, int x);

//errors_handler 
void	check_player_exists(t_map *game);
void	ft_error(char *msg, t_map game);
void	ft_error_fd(char *msg, int fd);
void	check_player_pos(char **map, int y, int x);

//raycast
void	raycasting(t_map *game);
t_img_d	*set_texture_cardinal_pos(t_map *game, t_raycast *ray);
void	set_map_dimensions(t_map *game);

//parse_cub
void	parse_cub(char *file, t_map *game);
void	parse_header_or_map(char *line, t_map *game);
char	*read_line(int fd);
void	parse_line(char *line, t_map *game);

//save
void	save_map_line(char *line, t_map *game);
void	save_texture(char *line, t_map *game);
void	save_color(char *line, t_map *game);
void	save_texture(char *line, t_map *game);

//detector
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_color(char *line);
int		is_texture(char *line);
int		exist_obj(char *s);

//utils
void	cub_free(char **str);
void	*ft_mem(size_t bytes);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	free_realloc(void *s);
void	my_pixel_put(t_map *game, int x, int y, int color);
int		get_texture_color(t_img_d *tex, int tx, int ty);
char	*ft_strdup_v2(char *src);

//test
void	calculate_line_height(t_raycast *ray);
void	draw_vertical_line(t_map *game, t_raycast *ray, int x);
void	calculate_wall_distance(t_map *game, t_raycast *ray);
void	perform_dda(t_map *game, t_raycast *ray);
void	calculate_step_and_side_dist(t_map *game, t_raycast *ray);
void	init_raycast(t_map *game, t_raycast *ray, int x);
void	raycasting(t_map *game);

//keyhooks
int		handle_keypress(int keycode, t_map *game);
int		handle_release(int keycode, t_map *game);
int		update_game(t_map *game);
int		handle_close(t_map *game);
void	move_forward(t_map *game);
void	move_backward(t_map *game);
void	move_left(t_map *game);
void	move_right(t_map *game);
void	rotate_left(t_map *game);
void	rotate_right(t_map *game);

//init_img
void	init_imgs(t_map *game);
void	init_texture_no(t_map *game, int index, int width, int height);
void	init_texture_so(t_map *game, unsigned int index, int width, int height);
void	init_texture_we(t_map *game, unsigned int index, int width, int height);
void	init_texture_ea(t_map *game, unsigned int index, int width, int height);

//check
//int		check_map(t_map *game);
void	check_map(char **map);
int		parse_rgb(char *str, t_map *game);
int		check_filename(char	*filename);
void	check_player_dir(t_map *game, int dir);
//init
void	init_all(t_map *game);
void	init_window(t_map *game);
void	init_parse(t_map *game, char *str);
void	init_player(t_map *game);

#endif
