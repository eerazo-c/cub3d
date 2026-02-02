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

void    draw_wall(t_map *game, t_raycast *ray, int x, t_img_d *texture, int tex_x)
{
    int     color;
    double  tex_step;
    double  tex_pos;
    int     tex_y;
    int     y;

    tex_step = (double)texture->height / (double)ray->line_height;
    tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tex_step;
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        tex_y = (int)tex_pos;
        if (tex_y < 0)
            tex_y = 0;
        if (tex_y >= texture->height)
            tex_y = texture->height - 1;
        color = get_texture_color(texture, tex_x, tex_y);
        my_pixel_put(game, x, y, color);
        tex_pos += tex_step;
        y++;
    }
}

void    draw_floor(t_map *game, int x, int draw_end)
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
    t_img_d  *texture;
    int         tex_x;

    texture = set_texture_cardinal_pos(game, ray);
    tex_x = get_texture_wall(game, ray, texture);
    draw_ceiling(game, x, ray->draw_start);
    draw_wall(game, ray, x, texture, tex_x);
    draw_floor(game, x, ray->draw_end);
}
