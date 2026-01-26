#include "cub3d.h"

void	raycasting(t_map *game)
{
	t_raycast	ray;
	int			x;
    
	x = 0;
	while (x < WIDTH)
	{
		init_raycast(game, &ray, x);
		calculate_step_and_side_dist(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance(game, &ray);
		calculate_line_height(&ray);
		draw_vertical_line(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, 0, 0);
}

void    init_raycast(t_map *game, t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;

	ray->ray_dir_x = game->player.dir_x + game->player.plane_x
            * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y
            * ray->camera_x;

	ray->map_x = (int)(game->player.pos_x);
	ray->map_y = (int)(game->player.pos_y);

	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void    perform_dda(t_map *game, t_raycast *ray)
{
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (game->map[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}

void	draw_vertical_line(t_map *game, t_raycast *ray, int x)
{
    int			y;
    int			color;
    t_img_data	*texture;
    int			tex_x;
    double		wall_x;
    double		tex_step;
    double		tex_pos;
    int			tex_y;

    // Elegir textura según lado y dirección del rayo
    if (ray->side == 0)  // Pared vertical (impacto en X)
    {
        if (ray->ray_dir_x > 0)
            texture = &game->imgs[4];  // Este
        else
            texture = &game->imgs[3];  // Oeste
    }
    else  // Pared horizontal (impacto en Y)
    {
        if (ray->ray_dir_y > 0)
            texture = &game->imgs[2];  // Sur
        else
            texture = &game->imgs[1];  // Norte
    }

    // Calcular wall_x: punto exacto en la pared (0..1)
    // Esta es la parte crítica
    if (ray->side == 0)  // Pared vertical
    {
        // La coordenada Y donde el rayo intersecta la pared vertical
        wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    }
    else  // Pared horizontal
    {
        // La coordenada X donde el rayo intersecta la pared horizontal
        wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    }
    
    // Normalizar wall_x a rango [0, 1]
    wall_x -= floor(wall_x);
    
    // tex_x: columna de la textura
    tex_x = (int)(wall_x * (double)texture->width);
    if (tex_x >= texture->width)
        tex_x = texture->width - 1;
    if (tex_x < 0)
        tex_x = 0;
    
    // Calcular paso vertical y posición inicial en la textura
    tex_step = (double)texture->height / (double)ray->line_height;
    tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tex_step;
    
    // Dibujar techo
    y = 0;
    while (y < ray->draw_start)
    {
        my_pixel_put(game, x, y, game->ceiling_color);
        y++;
    }
    
    // Dibujar la pared con textura
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
    
    // Dibujar suelo
    y = ray->draw_end;
    while (y < HEIGHT)
    {
        my_pixel_put(game, x, y, game->floor_color);
        y++;
    }
}


// no se llama nunca pero la dejo por si acaso
void cleanup_raycast(t_map *game)
{
    int total_bytes;
    
    total_bytes = game->imgs->line_length * game->imgs->height;
    ft_memset(game->imgs->addr, 0, total_bytes);  
}