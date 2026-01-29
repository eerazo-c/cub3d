/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:56 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/20 17:14:29 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_error(char *msg, t_map game)
{
	(void)game;
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	ft_error_fd(char *msg, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(1);
}

void	ft_error_fd_exvalue(char *msg, int fd, int exitvalue)
{
	ft_putendl_fd(msg, fd);
	exit(exitvalue);
}

void	check_player_pos(char **map, int y, int x)
{
	if (map[y - 1][x] == ' ')
		ft_error_fd("ERROR: Player is not in a valid position", 1);
	if (map[y + 1][x] == '\0' || map[y + 1][x] == '\n' || map[y + 1][x] == ' ')
		ft_error_fd("ERROR: Player is not in a valid position", 1);
	if (map[y][x - 1] == ' ')
		ft_error_fd("ERROR: Player is not in a valid position", 1);
	if (map[y][x + 1] == '\0' || map[y][x + 1] == '\n' || map[y][x + 1] == ' ')
		ft_error_fd("ERROR: Player is not in a valid position", 1);
}

void	check_player_exists(t_map *game)
{
	size_t	i;
	size_t	j;
	int		player_count;

	i = 0;
	player_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W' )
			{
				if (player_count == 1)
					ft_error_fd("ERROR:Multiple Players", 1);
				player_count++;
				check_player_pos(game->map, i, j);
			}
			j++;
		}
		i++;
	}
	if (player_count == 0)
		ft_error_fd("ERROR: no players", 1);
}
