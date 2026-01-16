#include "cub3d.h"

void    raycasting(t_map *game)
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
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->imgs, 0, 0);
}

void    init_raycast(t_map *game, t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;

	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;

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

void    draw_vertical_line(t_map *game, t_raycast *ray, int x)
{
    int y;
    int color;
    
    // Elegir color según el lado (para dar sensación de profundidad)
    if (ray->side == 0)
        color = 0xFF0000;     // Paredes verticales (norte) en rojo
    else
        color = 0x990000;     // Paredes horizontales (este) en azul
    y = 0;
    while (y < ray->draw_start)
    {
        my_pixel_put(game, x, y, game->ceiling_color);
        y++;
    }
    
    // Dibujar la pared
    // TODO colocar las texturas para las diferentes paredes dependiendo de la dirección 
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        my_pixel_put(game, x, y, color);
        y++;
    }

    y = ray->draw_end;
    while (y < HEIGHT)
    {
        my_pixel_put(game, x, y, game->floor_color);
        y++;
    }
}
/*
void    draw_vertical_line_with_texture(t_map *game, t_raycast *ray, int x)
{
    int y;
    int tex_x;      // Posición X en la textura
    int tex_y;      // Posición Y en la textura
    int color;
    t_img_data *texture; 
    
    // Elegir textura según la dirección
    if (ray->side == 0)  // Norte o Sur
    {
        if (ray->ray_dir_x > 0)
            texture = &game->imgs[0];   // Mirando este
        else
            texture = &game->imgs[1];   // Mirando oeste
    }
    else  // Este o Oeste
    {
        if (ray->ray_dir_y > 0)
            texture = &game->imgs[2];  // Mirando sur
        else
            texture = &game->imgs[3];  // Mirando norte
    }
    
    // Calcular tex_x (qué columna de la textura usar)
    // ... cálculos ...
    
    // Dibujar techo
    y = 0;
    while (y < ray->draw_start)
    {
        my_pixel_put(game, x, y, game->ceiling_color);
        y++;
    }
    
    // Dibujar pared con textura
    y = ray->draw_start;
    while (y <= ray->draw_end)
    {
        // Calcular qué fila de la textura usar
        tex_y = (y - ray->draw_start) * texture->height / ray->line_height;
        
        // Obtener el color de la textura
        color = get_texture_color(texture, tex_x, tex_y);
        
        my_pixel_put(game, x, y, color);
        y++;
    }
    
    // Dibujar suelo
    y = ray->draw_end + 1;
    while (y < HEIGHT)
    {
        my_pixel_put(game, x, y, game->floor_color);
        y++;
    }
}
*/
void cleanup_raycast(t_map *game)
{
    int total_bytes;
    
    total_bytes = game->imgs->line_length * game->imgs->height;
    ft_memset(game->imgs->addr, 0, total_bytes);  
}