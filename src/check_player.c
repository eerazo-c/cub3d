/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:48:35 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/29 20:50:08 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	check_player_nord_south(t_map *game, int dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.plane_y = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.60;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.plane_y = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.60;
	}
}

static void	check_player_east_west(t_map *game, int dir)
{
	if (dir == 'W')
	{
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.dir_x = -1;
		game->player.plane_y = -0.60;
	}
	else if (dir == 'E')
	{
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.dir_x = 1;
		game->player.plane_y = 0.60;
	}
}

void	check_player_dir(t_map *game, int dir)
{
	if (dir == 'N' || dir == 'S')
		check_player_nord_south(game, dir);
	else if (dir == 'E' || dir == 'W')
	{
		check_player_east_west(game, dir);
	}
}
