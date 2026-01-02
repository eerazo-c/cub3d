#include "cub3d.h"

void	check_arg(int argc, char **argv)
{
	if (argc == 1)
		ft_error_fd("ERROR: no map loaded", 1);
	else if (argc == 2)
	{
		if (check_filename(argv[1]) == -1)
			ft_error_fd("ERROR: file must contain ext. '.cub' or exist", 1);
	}
	else
		ft_error_fd("ERROR: number of arguments invalid", 1);
}

void	ft_error(char *msg, t_map *game)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	ft_error_fd(char *msg, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(1);
}

void	ft_error_fd_exvalue(char *msg, int fd, int exitvalue)
{
	ft_putendl_fd(msg, fd);
	exit(exitvalue);
}

int	check_filename(char	*filename)
{
	char	*ext;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ext = ".cub";
	if (ft_strlen(filename) <= 4)
		return (-1);
	while (filename[i])
		i++;
	i = i - 4;
	while (filename[i])
	{
		if (filename[i++] == ext[j++])
			continue ;
		else
			return (-1);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_map game;
	check_arg(argc, argv);
// cambiar para 3d	read_map(argv, &game);
//  modificar para 3d	check_map_empty(&game);
//   "               "           " 	check_map(&game);
	game.mlx_ptr = mlx_init();
// talvex 	init_imgs(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
			game.height * SIZE, "Pulpolifactico");
	if (!game.win_ptr)
		ft_error_fd("ERROR: Window returned null", 1);
//puede 	draw_map(&game); 
	mlx_hook(game.win_ptr, ON_KEYPRESS, 1L << 0, player_movement, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 1L << 0, free_maps_close, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
