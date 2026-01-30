/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:00:51 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/30 14:36:20 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	save_color(char *line, t_map *game)
{
	int	i;

	i = 0;
	if (ft_strchr(line, 'F'))
	{
		if (game->floor_exist == 1)
			ft_error("ERROR: floor color duplicated", *game);
		while (line[i] && line[i] != ' ')
			i++;
		game->floor_color = parse_rgb(line + i, game);
		game->floor_exist = 1;
	}
	else if (ft_strchr(line, 'C'))
	{
		if (game->ceiling_exist == 1)
			ft_error("ERROR: ceiling color duplicated", *game);
		while (line[i] && line[i] != ' ')
			i++;
		game->ceiling_color = parse_rgb(line + i, game);
		game->ceiling_exist = 1;
	}
}

static int	check_duplicates_text(t_map *game, char *line, char c)
{
	int	i;

	i = 2;
	if (c == 'N' && game->cardinal.no)
		ft_error_fd("ERROR: NO duplicated", 1);
	if (c == 'S' && game->cardinal.so)
		ft_error_fd("ERROR: SO duplicated", 1);
	if (c == 'W' && game->cardinal.we)
		ft_error_fd("ERROR: WE duplicated", 1);
	if (c == 'E' && game->cardinal.ea)
		ft_error_fd("ERROR: EA duplicated", 1);
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

void	save_texture(char *line, t_map *game)
{
	int	i;

	if (ft_strchr(line, 'N'))
	{
		i = check_duplicates_text(game, line, 'N');
		game->cardinal.no = ft_strdup(line + i);
	}
	else if (ft_strchr(line, 'S'))
	{
		i = check_duplicates_text(game, line, 'S');
		game->cardinal.so = ft_strdup(line + i);
	}
	else if (ft_strchr(line, 'W'))
	{
		i = check_duplicates_text(game, line, 'W');
		game->cardinal.we = ft_strdup(line + i);
	}
	else if (ft_strchr(line, 'E'))
	{
		i = check_duplicates_text(game, line, 'E');
		game->cardinal.ea = ft_strdup(line + i);
	}
}

static void	add_map_line(char *line, t_map *game)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		ft_error_fd("ERROR: malloc failed, en add map line", 1);
	while (j < i)
	{
		new_map[j] = game->map[j];
		j++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
	{
		free(new_map);
		ft_error_fd("ERROR: ft_strdup failed in add_map_line", 1);
	}
	new_map[i + 1] = NULL;
	free(game->map);
	game->map = new_map;
}

void	save_map_line(char *line, t_map *game)
{
	if (!game->map)
		init_map(line, game);
	else
		add_map_line(line, game);
}
