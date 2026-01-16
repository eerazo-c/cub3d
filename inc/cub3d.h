#ifndef	CUB3D_H 
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

# define ON_KEYPRESS 2
# define ON_DESTROY 17

# define WIDTH	1080
# define HEIGHT	1000

# define ESC 65307

# define K_LEFT 65361
# define K_RIGHT 65363

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
/*
typedef struct s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img_data;
*/
typedef struct s_img_data
{
    void	*img_ptr;      		
    char	*addr;         		// Puntero al primer píxel (buffer de memoria)
    int		bpp;	// Número de bits por píxel (BPP), usualmente 32
    int		line_length;    		// Tamaño de una línea en bytes
    int		endian;        			 // Orden de los bytes (little/big endian)
    int		width;
    int		height;            //por si falla el char addr.
	int		size_l;
} t_img_data;

typedef struct s_player
{
	double	speed;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		look;		//direcion dende mira
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
    double	camera_x;      // Posición x en el plano de la cámara (-1 a 1)

    double	ray_dir_x;     // Dirección del rayo en X
    double	ray_dir_y;     // Dirección del rayo en Y

    int		map_x;         // Posición del rayo en el mapa (coordenada X)
    int		map_y;         // Posición del rayo en el mapa (coordenada Y)

    double	side_dist_x;   // Distancia al siguiente lado X
    double	side_dist_y;   // Distancia al siguiente lado Y

    double	delta_dist_x;  // Distancia que recorre el rayo entre cada X
    double	delta_dist_y;  // Distancia que recorre el rayo entre cada Y

    int		step_x;        // Dirección de paso en X (-1 o 1)
    int		step_y;        // Dirección de paso en Y (-1 o 1)
    int		hit;           // ¿El rayo tocó una pared? (0 o 1)
    int		side;          // ¿Qué lado de la pared tocó? (0=X, 1=Y)

    double	perp_wall_dist;	 // Distancia perpendicular a la pared
    int		line_height;    // Altura de la línea a dibujar
    int		draw_start;     // Píxel donde empieza a dibujar la pared
    int		draw_end;       // Píxel donde termina de dibujar la pared
}   			t_raycast;

typedef struct s_map
{
	void		*mlx_ptr; //puntero para inciar minili
	void		*win_ptr; //pntero para la ventana
	t_cardinal	cardinal;
	char		**map;
	int			floor_color;
	int			floor_exist;
	int			ceiling_exist;
	int			ceiling_color;
	int			map_started;
	t_player	player;
	t_img_data	*imgs;
}				t_map;

//PROTOTIPO_FUNCIONES

//main
void	check_arg(int argc, char **argv);
int		check_filename(char	*filename);
void	init_all(t_map *game);
void	init_window(t_map *game);
void	init_parse(t_map *game, char *str);

//parse_cub
void	parse_cub(char *file, t_map *game);
void	parse_header_or_map(char *line, t_map *game);
char	*read_line(int fd);
void	parse_line(char *line, t_map *game);

//map
void	save_map_line(char *line, t_map *game);
void	save_texture(char *line, t_map *game);
void	save_color(char *line, t_map *game);
void	save_texture(char *line, t_map *game);
int		parse_rgb(char *str, t_map *game);

//detector
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_color(char *line);
int		is_texture(char *line);

//utils
void	cub_free(char **str);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	ft_error(char *msg, t_map game);
void	ft_error_fd(char *msg, int fd);
void	my_pixel_put(t_map *game, int x, int y, int color);
int		get_texture_color(t_img_data *tex, int tx, int ty);

//test
void	calculate_line_height(t_raycast *ray);
void	draw_vertical_line(t_map *game, t_raycast *ray, int x);
void	calculate_wall_distance(t_map *game, t_raycast *ray);
void	perform_dda(t_map *game, t_raycast *ray);
void	calculate_step_and_side_dist(t_map *game, t_raycast *ray);
void	init_raycast(t_map *game, t_raycast *ray, int x);
void	raycasting(t_map *game);
void	init_player(t_map *game);

//keyhooks
int		handle_keypress(int keycode, t_map *game);
int		handle_close(t_map *game);
void	move_forward(t_map *game);
void	move_backward(t_map *game);
void	move_left(t_map *game);
void	move_right(t_map *game);
void	rotate_left(t_map *game);
void	rotate_right(t_map *game);
//init
void	init_imgs(t_map *game);
int		exist_obj(char c);

#endif
