#include "cub3d.h"

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
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (game->player.pos_x - ray->map_x)
            * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
            * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (game->player.pos_y - ray->map_y)
            * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
            * ray->delta_dist_y;
    }
}

void	calculate_wall_distance(t_map *game, t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.pos_x
            + (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.pos_y
            + (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	if (ray->perp_wall_dist < 0.001)
		ray->perp_wall_dist = 0.001;
}