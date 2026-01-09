/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:51:23 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/05 21:27:13 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <stdio.h>

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

void	init_all(t_map *game)
{
	if (!game->mlx_ptr)
		ft_error_fd("ERROR: mlx initialization failed", 1);
	init_window(game);
}

void	init_window(t_map *game)
{
	if (!game->mlx_ptr)
		ft_error_fd("ERROR: mlx initialization failed", 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Pulpito");
	if (!game->win_ptr)
		ft_error_fd("ERROR: Window returned null", 1);
}

int	main(int argc, char **argv)
{
	t_map	game;

	check_arg(argc, argv);
	ft_bzero(&game, sizeof(t_map));
	game.floor_exist = 0;
	game.ceiling_exist = 0;

	parse_cub(argv[1], &game);
	printf("TESTEANDO f, %c\n", game.floor_color);
	printf("TESTEANDO c, %c\n", game.ceiling_color);
	printf("NO = %s\n", game.no);
	printf("SO = %s\n", game.so);
	printf("WE = %s\n", game.we);
	printf("EA = %s\n", game.ea);
// cambiar para 3d	read_map(argv, &game);
//  modificar para 3d	check_map_empty(&game);
//  check_map(&game);
	game.mlx_ptr = mlx_init();
	init_window(&game);
// talvex 	init_imgs(&game);

//puede 	draw_map(&game); 
/*	mlx_hook(game.win_ptr, ON_KEYPRESS, 1L << 0, player_movement, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 1L << 0, free_maps_close, &game);
*/
	mlx_loop(game.mlx_ptr);
	return (0);
}
