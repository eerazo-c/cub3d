#include "cub3d.h"

int handle_keypress(int keycode, t_map *game)
{
    // ESC - Cerrar el programa
    if (keycode == ESC)
        handle_close(game);
    
    // W - Mover hacia adelante (en la dirección que mira el jugador)
    if (keycode == KEY_W)
        move_forward(game);
    
    // S - Mover hacia atrás (retroceder)
    if (keycode == KEY_S)
        move_backward(game);
    
    // A - Moverse a la izquierda (strafe left)
    if (keycode == KEY_A)
        move_left(game);
    
    // D - Moverse a la derecha (strafe right)
    if (keycode == KEY_D)
        move_right(game);
    
    // Flecha izquierda - Rotar cámara a la izquierda
    if (keycode == K_LEFT)
        rotate_left(game);
    
    // Flecha derecha - Rotar cámara a la derecha
    if (keycode == K_RIGHT)
        rotate_right(game);
    
    // Después de cualquier movimiento, volver a dibujar la escena
    printf("Player Position: (%.2f, %.2f) Direction: (%.2f, %.2f)\n",
           game->player.pos_x, game->player.pos_y,
           game->player.dir_x, game->player.dir_y);
    raycasting(game);
    
    return (0);
}

// Se ejecuta cuando haces clic en la X de la ventana
int handle_close(t_map *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    exit(0);
    return (0);
}

void    move_forward(t_map *game)
{
    double new_x;
    double new_y;
    
    // Calcular nueva posición basada en la dirección del jugador
    // Multiplicamos por speed para controlar la velocidad
    new_x = game->player.pos_x + game->player.dir_x * game->player.speed;
    new_y = game->player.pos_y + game->player.dir_y * game->player.speed;
    
    // Verificar colisión en X
    // Solo nos movemos si la nueva posición NO es una pared ('1')
    if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
        game->player.pos_x = new_x;
    
    // Verificar colisión en Y
    if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_y;
}

void    move_backward(t_map *game)
{
    double new_x;
    double new_y;
    
    // Similar a move_forward pero restamos la dirección
    // (vamos en dirección opuesta)
    new_x = game->player.pos_x - game->player.dir_x * game->player.speed;
    new_y = game->player.pos_y - game->player.dir_y * game->player.speed;
    
    // Verificar colisiones
    if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
        game->player.pos_x = new_x;
    
    if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_y;
}

void    move_left(t_map *game)
{
    double new_x;
    double new_y;
    
    // Para movernos lateralmente, usamos el vector perpendicular a la dirección
    // El vector perpendicular a (dir_x, dir_y) es (-dir_y, dir_x)
    // Esto nos mueve a la izquierda del jugador
    
    new_x = game->player.pos_x + game->player.dir_y * game->player.speed;
    new_y = game->player.pos_y - game->player.dir_x * game->player.speed;
    
    // Verificar colisiones
    if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
        game->player.pos_x = new_x;
    
    if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_y;
}

void    move_right(t_map *game)
{
    double new_x;
    double new_y;
    
    // Movimiento perpendicular hacia la derecha
    // Es el opuesto del move_left
    new_x = game->player.pos_x - game->player.dir_y * game->player.speed;
    new_y = game->player.pos_y + game->player.dir_x * game->player.speed;
    
    // Verificar colisiones
    if (game->map[(int)game->player.pos_y][(int)new_x] != '1')
        game->player.pos_x = new_x;
    
    if (game->map[(int)new_y][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_y;
}

void    rotate_left(t_map *game)
{
    double old_dir_x;
    double old_plane_x;
    double rot_speed;
    
    // Velocidad de rotación (en radianes)
    // 0.05 radianes ≈ 2.86 grados por frame
    rot_speed = 0.15;
    
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
    rot_speed = -0.05;
    
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