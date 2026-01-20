/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:11:33 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/20 17:28:11 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

// test  no tomar en cuenta
int	check_map(t_map *game)
{
    unsigned long	i;
    size_t			len;

    if (!game || !game->map || game->map_width == 0 || game->map_height == 0)
        return (-1);
    i = 0;
    while (i < game->map_width)
    {
        len = ft_strlen(game->map[0]);
        if (len > 0 && game->map[0][len - 1] == '\n')
            len--;
        if (i >= len || game->map[0][i] != '1')
            return (-1);
        
        len = ft_strlen(game->map[game->map_height - 1]);
        if (len > 0 && game->map[game->map_height - 1][len - 1] == '\n')
            len--;
        if (i >= len || game->map[game->map_height - 1][i] != '1')
            return (-1);
        i++;
    }
    i = 0;
    while (i < game->map_height)
    {
        len = ft_strlen(game->map[i]);
        if (len > 0 && game->map[i][len - 1] == '\n')
            len--;
        if (game->map[i][0] != '1')
            return (-1);
        if (len == 0 || game->map[i][len - 1] != '1')
            return (-1);
        i++;
    }
    return (0);
}


/*int	check_map(t_map *game)
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
}*/

static void	pad_map_line(int row_index, int target_width, t_map *game)
{
	char	*new_line;
	char	*old_line;
	int		i;
	int		len;

	old_line = game->map[row_index];
	len = ft_strlen(old_line);
	if (len > 0 && old_line[len - 1] == '\n')
		len--;
	if (len >= target_width)
		return ;
	new_line = malloc(sizeof(char) * (target_width + 2));
	if (!new_line)
		ft_error("ERROR: malloc failed in pad_map_line", *game);
	i = 0;
	while (i < len)
	{
		new_line[i] = old_line[i];
		i++;
	}
	while (i < target_width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\n';
	new_line[i + 1] = '\0';
	free(old_line);
	game->map[row_index] = new_line;
}

void	set_map_dimensions(t_map *game)
{
	unsigned int	i;
	unsigned int	max_width;
	int				len;

	i = 0;
	max_width = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len > 0 && game->map[i][len - 1] == '\n')
			len--;
		if ((unsigned int)len > max_width)
			max_width = (unsigned int)len;
		i++;
	}
	game->map_width = max_width;
	game->map_height = i;
	// Rellenar filas cortas con espacios
	i = 0;
	while (i < game->map_height)
	{
		pad_map_line(i, max_width, game);
		i++;
	}
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


