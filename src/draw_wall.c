/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:44:19 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/30 14:53:36 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	get_texture_wall(t_map *game, t_raycast *ray, t_img_d *text)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)text->width);
	if (tex_x >= text->width)
		tex_x = text->width - 1;
	if (tex_x < 0)
		tex_x = 0;
	return (tex_x);
}

static int	get_tex_y(t_img_d *texture, double tex_pos)
{
	int	tex_y;

	tex_y = (int)tex_pos;
	if (tex_y < 0)
		return (0);
	if (tex_y >= texture->height)
		return (texture->height - 1);
	return (tex_y);
}

void	draw_wall(t_map *game, t_raycast *ray, int x, t_img_d *texture)
{
	int		color;
	double	tex_step;
	double	tex_pos;
	int		tex_x;
	int		y;

	tex_x = get_texture_wall(game, ray, texture);
	tex_step = (double)texture->height / (double)ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tex_step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		color = get_texture_color(texture, tex_x, get_tex_y(texture, tex_pos));
		my_pixel_put(game, x, y, color);
		tex_pos += tex_step;
		y++;
	}
}
