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

t_img_data    *set_texture_cardinal_pos(t_map *game, t_raycast *ray)
{
    t_img_data  *texture;

    if (ray->side == 0)
    {
        if (ray->ray_dir_x > 0)
            texture = &game->imgs[4];
        else
            texture = &game->imgs[3];
    }
    else
    {
        if (ray->ray_dir_y > 0)
            texture = &game->imgs[2];
        else
            texture = &game->imgs[1];
    }
    if (texture == NULL)
        ft_error_fd("Error: textura no cargada(raycast)", 1);
    return (texture);
}
