/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:02:31 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/05 21:28:13 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

char *read_line(int fd)
{
	char	*buffer;
	char	xchar;
	int		byte;
	int		index;

	index = 0;
	byte = read(fd, &xchar, 1);
	buffer = malloc(sizeof(char) * 2);
	while (byte > 0)
	{
		if (xchar == '\n')
			break ;
		buffer[index++] = xchar;
		buffer = ft_realloc(buffer, ft_strlen(buffer) + 1, ft_strlen(buffer) + 2);
		byte = read(fd, &xchar, 1);
	}
	if ((byte <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}

void	parse_cub(char *file, t_map game)
{
	(void)game;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_fd("ERROR: cannot open file", 1);

	line = read_line(fd);
	while (line)
	{
		//parse_line(line, game);
		free(line);
		line = read_line(fd);
	}
	close(fd);
}
