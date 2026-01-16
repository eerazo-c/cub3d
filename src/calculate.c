#include "cub3d.h"

// Calcula la altura de la línea a dibujar
void    calculate_line_height(t_raycast *ray)
{
    ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);

    ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    
    ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = HEIGHT - 1;
}

void    calculate_step_and_side_dist(t_map *game, t_raycast *ray)
{
    // ¿Hacia dónde avanza el rayo en X?
    if (ray->ray_dir_x < 0)  // El rayo va hacia la izquierda
    {
        ray->step_x = -1;
        ray->side_dist_x = (game->player.pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else  // El rayo va hacia la derecha
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) * ray->delta_dist_x;
    }
    
    // ¿Hacia dónde avanza el rayo en Y?
    if (ray->ray_dir_y < 0)  // El rayo va hacia arriba
    {
        ray->step_y = -1;
        ray->side_dist_y = (game->player.pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else  // El rayo va hacia abajo
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) * ray->delta_dist_y;
    }
}
//  Calcula la distancia perpendicular a la pared y evitamos el efecto "ojo de pez"
void	calculate_wall_distance(t_map *game, t_raycast *ray)
{
	if (ray->side == 0)
	{
		// Pared vertical: distancia hasta la pared X
		// Si step_x = 1, la pared está en map_x + 1
		// Si step_x = -1, la pared está en map_x
		if (ray->step_x == 1)
			ray->perp_wall_dist = (ray->map_x + 1.0 - game->player.pos_x)
				/ ray->ray_dir_x;
		else
			ray->perp_wall_dist = (ray->map_x - game->player.pos_x)
				/ ray->ray_dir_x;
	}
	else
	{
		// Pared horizontal: distancia hasta la pared Y
		// Si step_y = 1, la pared está en map_y + 1
		// Si step_y = -1, la pared está en map_y
		if (ray->step_y == 1)
			ray->perp_wall_dist = (ray->map_y + 1.0 - game->player.pos_y)
				/ ray->ray_dir_y;
		else
			ray->perp_wall_dist = (ray->map_y - game->player.pos_y)
				/ ray->ray_dir_y;
	}
}