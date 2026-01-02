#ifndef	CUB3D_H 
# define CUB3D_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

# define WIDTH	1000
# define HEIGHT	1000

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
# define S_DOWN 5
# define S_UP 4
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_UP 65362
# define K_DOWN 65364
# define ZOOM_IN 65451 // Keypad +
# define ZOOM_OUT 65453 // Keypad -
# define BUTTON5 5
# define BUTTON4 4

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

typedef struct s_img_data
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img_data;

typedef struct s_map
{
	char		*raw_map;
	char		**map;
	size_t		height;
	size_t		width;
	t_pos		player;
	int			ex;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	*imgs;
	size_t		x;
	size_t		y;

}				t_map;

//PROTOTIPO_FUNCIONES
	


#endif
