/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:23:20 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/20 17:30:01 by elerazo          ###   ########.fr       */
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
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W' )
			{
				check_player_dir(game, game->map[i][j]);
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				game->player.speed = 0.05;
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
	check_player_exists(game);

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
	if (!game->map)
		printf("\033[1;31mERROR\033[0m\n:malloc failed '%p\n'", game);
}
