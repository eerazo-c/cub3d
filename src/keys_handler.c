#include "cub3d.h"

int handle_keypress(int keycode, t_map *game)
{
    if (keycode == ESC)
        handle_close(game);
    if (keycode == KEY_W)
        move_forward(game);
    if (keycode == KEY_S)
        move_backward(game);
    if (keycode == KEY_A)
        move_left(game);
    if (keycode == KEY_D)
        move_right(game);
    if (keycode == K_LEFT)
        rotate_left(game);
    if (keycode == K_RIGHT)
        rotate_right(game);       
    printf("Player Position: (%.2f, %.2f) Direction: (%.2f, %.2f)\n",
           game->player.pos_x, game->player.pos_y,
           game->player.dir_x, game->player.dir_y);
    raycasting(game);
    return (0);
}

int handle_close(t_map *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(0);
    return (0);
}

void    rotate_left(t_map *game)
{
    double old_dir_x;
    double old_plane_x;
    double rot_speed;
    
    // Velocidad de rotación (en radianes)
    // 0.05 radianes ≈ 2.86 grados por frame
    rot_speed = -0.05;
    
    // Guardar valores antiguos
    old_dir_x = game->player.dir_x;
    old_plane_x = game->player.plane_x;
    
    // Aplicar matriz de rotación 2D a la dirección
    // Fórmula: rotación antihoraria (counterclockwise)
    // new_x = x * cos(θ) - y * sin(θ)
    // new_y = x * sin(θ) + y * cos(θ)
    
    game->player.dir_x = game->player.dir_x * cos(rot_speed) 
                         - game->player.dir_y * sin(rot_speed);
    game->player.dir_y = old_dir_x * sin(rot_speed) 
                         + game->player.dir_y * cos(rot_speed);
    
    // Aplicar la misma rotación al plano de la cámara
    game->player.plane_x = game->player.plane_x * cos(rot_speed) 
                           - game->player.plane_y * sin(rot_speed);
    game->player.plane_y = old_plane_x * sin(rot_speed) 
                           + game->player.plane_y * cos(rot_speed);
}

void    rotate_right(t_map *game)
{
    double old_dir_x;
    double old_plane_x;
    double rot_speed;
    
    // Velocidad de rotación (negativa para ir en sentido horario)
    rot_speed = 0.05;
    
    // Guardar valores antiguos
    old_dir_x = game->player.dir_x;
    old_plane_x = game->player.plane_x;
    
    // Aplicar matriz de rotación 2D (horaria = clockwise)
    game->player.dir_x = game->player.dir_x * cos(rot_speed) 
                         - game->player.dir_y * sin(rot_speed);
    game->player.dir_y = old_dir_x * sin(rot_speed) 
                         + game->player.dir_y * cos(rot_speed);
    
    // Rotar el plano de la cámara
    game->player.plane_x = game->player.plane_x * cos(rot_speed) 
                           - game->player.plane_y * sin(rot_speed);
    game->player.plane_y = old_plane_x * sin(rot_speed) 
                           + game->player.plane_y * cos(rot_speed);
}