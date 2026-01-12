#include "cub3d.h"

void    calculate_line_height(t_raycast *ray)
{
    // La altura de la pared es inversamente proporcional a la distancia
    // Cuanto más lejos, más pequeña se ve
    ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
    
    // Calcular dónde empieza y termina la línea en la pantalla
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

void    calculate_wall_distance(t_map *game, t_raycast *ray)
{
    // Calculamos la distancia PERPENDICULAR a la pared
    // (no la distancia euclidiana, para evitar el efecto "ojo de pez")
    
    if (ray->side == 0)  // Tocamos un lado X (vertical)
        ray->perp_wall_dist = (ray->map_x - game->player.pos_x + 
                               (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else  // Tocamos un lado Y (horizontal)
        ray->perp_wall_dist = (ray->map_y - game->player.pos_y + 
                               (1 - ray->step_y) / 2) / ray->ray_dir_y;
}