#include "cub3d.h"

void raycasting(t_map *game)
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
}

void init_raycast(t_map *game, t_raycast *ray, int x)
{
	// Calcular la posición x en el plano de la cámara
	ray->camera_x = 2 * x / (double)WIDTH - 1; // De -1 a 1

	// Calcular la dirección del rayo
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;

	// Determinar la posición del rayo en el mapa
	ray->map_x = (int)(game->player.pos_x);
	ray->map_y = (int)(game->player.pos_y);

	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void    perform_dda(t_map *game, t_raycast *ray)
{
    while (ray->hit == 0)  // Mientras no toquemos una pared
    {
        // Avanzar al siguiente cuadrado del mapa
        if (ray->side_dist_x < ray->side_dist_y)
        {
            // El siguiente lado X está más cerca
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;  // Tocamos un lado X (vertical)
        }
        else
        {
            // El siguiente lado Y está más cerca
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;  // Tocamos un lado Y (horizontal)
        }
        
        // Verificar si tocamos una pared (el valor '1' en el mapa)
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
        color = 16711824;     // Paredes verticales (norte-sur) en rojo
    else
        color = 11927777;     // Paredes horizontales (este-oeste) en azul
    
    // Dibujar el techo (parte superior)
    y = 0;
    while (y < ray->draw_start)
    {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, game->ceiling_color);
        y++;
    }
    
    // Dibujar la pared
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
        y++;
    }
    
    // Dibujar el suelo (parte inferior)
    y = ray->draw_end;
    while (y < HEIGHT)
    {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, game->floor_color);
        y++;
    }
}
