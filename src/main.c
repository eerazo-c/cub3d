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

void	init_player(t_map *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' /* || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W' */)
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				game->player.dir_x = 0;
				game->player.dir_y = -1;
				game->player.plane_x = 0.60; //FOV 66 grados
				game->player.plane_y = 0;
				game->player.speed = 0.3;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_all(t_map *game)
{
	game->mlx_ptr = mlx_init();
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

void	init_parse(t_map *game, char *str)
{
	ft_bzero(game, sizeof(t_map));
	game->floor_exist = 0;
	game->ceiling_exist = 0;
	parse_cub(str, game);

}

int	main(int argc, char **argv)
{
	t_map	game;

	check_arg(argc, argv);
	init_parse(&game, argv[1]);
	init_all(&game);
	init_player(&game);
	raycasting(&game);


	mlx_hook(game.win_ptr, ON_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 1L << 0, handle_close, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
