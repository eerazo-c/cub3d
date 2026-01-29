/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:11:33 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/27 15:25:48 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p == 'E' || p == 'W' )
		return (1);
	else
		return (0);
}

static int	check_map_floor(int y, int x, char **map)
{
	if (map[y - 1][x] == ' ' || map[y - 1][x] == '\0' || map[y + 1][x] == '\n')
		return (1);
	if (map[y + 1][x] == '\0' || map[y + 1][x] == '\n' || map[y + 1][x] == ' ')
		return (1);
	if (map[y][x - 1] == ' ')
		return (1);
	if (map[y][x + 1] == '\0' || map[y][x + 1] == '\n' || map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	check_map_spaces(int y, int x, char **map)
{
	if (map[y - 1][x] == '0' || is_player(map[y - 1][x]))
		return (1);
	if (map[y + 1][x] == '0' || is_player(map[y + 1][x]))
		return (1);
	if (map[y][x - 1] == '0' || is_player(map[y][x - 1]))
		return (1);
	if (map[y][x + 1] == '0' || is_player(map[y][x + 1]))
		return (1);
	return (0);
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	err;

	i = 0;
	err = 0;
	if (!map)
		ft_error_fd("Error: mapa error (checkmap)", 1);
	while (map[i] && err == 0)
	{
		exist_obj(map[i]);
		j = 0;
		while (map[i][j] && err == 0)
		{
			if (map[i][j] == '0')
				err = check_map_floor(i, j, map);
			j++;
		}
		i++;
	}
	if (err)
		ft_error_fd("Error: mapa error", 1);
}

int	parse_rgb(char *str, t_map *game)
{
	char			**rgb;
	int				r;
	int				g;
	int				b;
	unsigned int	color_hex;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		ft_error("ERROR: invalid RGB format", *game);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("ERROR: RGB values out of range", *game);
	cub_free(rgb);
	color_hex = (((unsigned int)r << 16) | ((unsigned int)g << 8) | b);
	return (color_hex);
}
