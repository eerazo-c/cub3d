#include "cub3d.h"

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