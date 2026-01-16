/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:11:33 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/16 18:16:06 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	check_map(t_map *game)
{
	unsigned long		i;

	i = 0;
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

void	check_arg(int argc, char **argv)
{
	if (argc == 1)
		ft_error_fd("ERROR: no map loaded", 1);
	else if (argc == 2)
	{
		if (check_filename(argv[1]) == -1)
			ft_error_fd("ERROR: file must contain ext. '.cub' or exist", 1);
	}
	else
		ft_error_fd("ERROR: number of arguments invalid", 1);
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
