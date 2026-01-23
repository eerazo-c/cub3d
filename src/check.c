/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:11:33 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/23 18:43:09 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p =='E' || p =='W' )
		return (1);
	else 
		return (0);
}

static int check_map_spaces(int y , int x, char **map)
{
/*	if (map[y][x] == '\0')
	{
		if(map[y-1][x] == '0' || is_player(map[y-1][x]))
			return (1);	
		if(map[y][x-1] == '0' || is_player(map[y][x-1]))
			return (1);
	}
	else if (map[y][x] == '\n')
	{
		if(map[y-1][x] == '0' || is_player(map[y-1][x]))
			return (1);	
		if(map[y+1][x] == '0' || is_player(map[y+1][x]))
			return (1);	
		if(map[y][x-1] == '0' || is_player(map[y][x-1]))
			return (1);
	}
	else if (map[y][x] == ' ')
	{*/
		if(map[y-1][x] == '0' || is_player(map[y-1][x]))
			return (1);
		if(map[y+1][x] == '0' || is_player(map[y+1][x]))
			return (1);
		if(map[y][x-1] == '0' || is_player(map[y][x-1]))
			return (1);
		if(map[y][x+1] == '0' || is_player(map[y][x+1]))
			return (1);
	//}
	return(0);
}

void	check_map(char **map)
{
	int	i;
	int	j;
	int	err;

	i = 0;
	err = 0;
	while (map[i] && err == 0)
	{
		exist_obj(map[i]);
		j = 0;
		while (map[i][j] && err == 0)
		{
			if (map[i][j] == ' ' || map[i][j] == '\n' || map[i][j] == '\0')
			{
				err = check_map_spaces(i, j, map);
			}
			j++;
		}
		i++;
	}
	if (err)
		ft_error_fd("Error: mapa error",1);
	printf("todo bien :D\n");
}

/*
int	check_map(t_map *game)
{
	unsigned long		i;

	i = 0;
	if (game->map == NULL)
		return (-1);
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height -1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->map_width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
*/

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

int	check_filename(char	*filename)
{
	char	*ext;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ext = ".cub";
	if (ft_strlen(filename) <= 4)
		return (-1);
	while (filename[i])
		i++;
	i = i - 4;
	while (filename[i])
	{
		if (filename[i++] == ext[j++])
			continue ;
		else
			return (-1);
	}
	return (0);
}

void	check_player_dir(t_map *game, int dir)
{
	if (dir == 'N' || dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.plane_y = 0;
		if (dir == 'S')
		{
			game->player.dir_y = 1;
			game->player.plane_x = -0.60;
		}
		else
		{
			game->player.dir_y = -1;
			game->player.plane_x = 0.60;
		}
	}
	else if (dir == 'E' || dir == 'W')
	{
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		if (dir == 'W')
		{
			game->player.dir_x = -1;
			game->player.plane_y = -0.60;
		}
		else
		{
			game->player.dir_x = 1;
			game->player.plane_y = 0.60;
		}
	}
}
