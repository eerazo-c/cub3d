/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:55:51 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/30 14:54:42 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	draw_ceiling(t_map *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		my_pixel_put(game, x, y, game->ceiling_color);
		y++;
	}
}

void	draw_floor(t_map *game, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < HEIGHT)
	{
		my_pixel_put(game, x, y, game->floor_color);
		y++;
	}
}

void	draw_vertical_line(t_map *game, t_raycast *ray, int x)
{
	t_img_d	*texture;

	texture = set_texture_cardinal_pos(game, ray);
	draw_ceiling(game, x, ray->draw_start);
	draw_wall(game, ray, x, texture);
	draw_floor(game, x, ray->draw_end);
}
