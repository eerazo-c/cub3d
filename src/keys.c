/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:50:08 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/16 19:55:20 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	move_forward(t_map *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * game->player.speed;
	new_y = game->player.pos_y + game->player.dir_y * game->player.speed;
	if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_backward(t_map *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * game->player.speed;
	new_y = game->player.pos_y - game->player.dir_y * game->player.speed;
	if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_left(t_map *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * game->player.speed;
	new_y = game->player.pos_y - game->player.dir_x * game->player.speed;
	if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	move_right(t_map *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * game->player.speed;
	new_y = game->player.pos_y + game->player.dir_x * game->player.speed;
	if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}
