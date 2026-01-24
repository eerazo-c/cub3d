/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:15:41 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/23 18:37:38 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int handle_keypress(int keycode, t_map *game)
{
	if (keycode == ESC)
		handle_close(game);
	if (keycode == KEY_W)
		game->keys.w = 1;
	if (keycode == KEY_S)
		game->keys.s = 1;
	if (keycode == KEY_A)
		game->keys.a = 1;
	if (keycode == KEY_D)
		game->keys.d = 1;
	if (keycode == K_LEFT)
		game->keys.rotateleft = 1;
	if (keycode == K_RIGHT)
		game->keys.rotateright = 1;
	return (0);
}

int handle_release(int keycode, t_map *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	if (keycode == KEY_S)
		game->keys.s = 0;
	if (keycode == KEY_A)
		game->keys.a = 0;
	if (keycode == KEY_D)
		game->keys.d = 0;
	if (keycode == K_LEFT)
		game->keys.rotateleft = 0;
	if (keycode == K_RIGHT)
		game->keys.rotateright = 0;
	return (0);
}

int update_game(t_map *game)
{
    int moved;
    
    moved = 0;
    if (game->keys.w && ++moved)
    move_forward(game);
    if (game->keys.s && ++moved)
    move_backward(game);
    if (game->keys.a && ++moved)
    move_left(game);
    if (game->keys.d && ++moved)
    move_right(game);
    if (game->keys.rotateleft && ++moved)
    rotate_left(game);
    if (game->keys.rotateright && ++moved)
    rotate_right(game);
    if (moved)
    raycasting(game);
    return (0);
}

/*
int update_game(t_map *game)
{
    int moved;

    moved = 0;
    if (game->keys.w)
    {
        move_forward(game);
        moved = 1;
    }
    if (game->keys.s)
    {
        move_backward(game);    
        moved = 1;
    }
    if (game->keys.a)
    {
        move_left(game);
        moved = 1;
    }
    if (game->keys.d)
    {
        move_right(game);
        moved = 1;
    }
    if (game->keys.rotateleft)
    {
        rotate_left(game);
        moved = 1;
    }
    if (game->keys.rotateright)
    {
        rotate_right(game);
        moved = 1;
    }
    if (moved)
        raycasting(game);
    return (0);
}*/

void	rotate_left(t_map *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = -0.02;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}

void	rotate_right(t_map *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.02;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}
