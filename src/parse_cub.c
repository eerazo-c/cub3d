/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:02:31 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/20 16:39:25 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <stdio.h>

void	parse_header_or_map(char *line, t_map *game)
{
	if (is_empty_line(line))
		return ;
	else if (is_texture(line))
		save_texture(line, game);
	else if (is_color(line))
		save_color(line, game);
	else if (is_map_line(line))
	{
		game->map_started = 1;
		save_map_line(line, game);
	}
	else
		ft_error("ERROR: invalid line in .cub", *game);
}

void	parse_line(char *line, t_map *game)
{
	if (!game->map_started)
		parse_header_or_map(line, game);
	else
		save_map_line(line, game);
}

char	*read_line(int fd)
{
	char	*buffer;
	char	xchar;
	int		byte;
	int		index;

	index = 0;
	byte = read(fd, &xchar, 1);
	buffer = malloc(sizeof(char) * 2); //revisar este malloc
	while (byte > 0)
	{
		if (xchar == '\n')
			break ;
		buffer[index++] = xchar;
		buffer = ft_realloc(buffer, ft_strlen(buffer)
				+ 1, ft_strlen(buffer) + 2);
		byte = read(fd, &xchar, 1);
	}
	if ((byte <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}

void	parse_cub(char *file, t_map *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_fd("ERROR: cannot open file", 1);
	line = read_line(fd);
	while (line)
	{
		parse_line(line, game);
		free(line);
		line = read_line(fd);
		i++;
	}
	close(fd);
	check_map(game->map); ////////////////////////// MAPPPPPPP
}
