/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:51:23 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/20 17:35:55 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	main(int argc, char **argv)
{
	t_map	game;

	check_arg(argc, argv);
	init_parse(&game, argv[1]);
	init_all(&game);
	init_imgs(&game);
	init_player(&game);
	raycasting(&game);
	mlx_hook(game.win_ptr, ON_KEYPRESS, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win_ptr, ON_KEYRELEASE, 1L << 1, handle_release, &game);
	mlx_hook(game.win_ptr, ON_DESTROY, 0, handle_close, &game);
	mlx_loop_hook(game.mlx_ptr, update_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
