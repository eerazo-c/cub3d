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
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

# define ON_KEYPRESS 2
# define ON_DESTROY 17

//fractol
# define WIDTH	1080
# define HEIGHT	10000

//colors
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple 
# define AQUA_DREAM 0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red//

# define ESC 65307
# define CTR 65507

# define K_LEFT 65361
# define K_RIGHT 65363

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
//struct  cosas fractol
/*
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		end;
	int		line_len;
}				t_img;

typedef struct s_plano
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	escape_value;
	int		interations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		move_act;

}		t_plano;
*/

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}				t_pos;

typedef struct s_img
{
    void	*img_ptr;      		
    char	*addr;         		// Puntero al primer píxel (buffer de memoria)
    int		bits_per_pixel;	// Número de bits por píxel (BPP), usualmente 32
    int		line_length;    		// Tamaño de una línea en bytes
    int		endian;        			 // Orden de los bytes (little/big endian)
    int		width;
    int		height;
} t_img;

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

typedef struct s_map
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*raw_map;
	char		**map;
	size_t		height;
	size_t		width;
	t_pos		player;
	int			ex;
	t_img		*imgs;
	size_t		x;
	size_t		y;

}				t_map;
//PROTOTIPO_FUNCIONES

void	check_arg(int argc, char **argv);
int		check_filename(char	*filename);
void	ft_error(char *msg, t_map *game);
void	ft_error_fd(char *msg, int fd);
void	ft_error_fd_exvalue(char *msg, int fd, int exitvalue); //poco se usa

void	init_all(t_map *game);
void	init_window(t_map *game);
#endif
