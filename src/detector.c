#include "cub3d.h"

int	is_textura(char *line)
{
	if (!ft_strncmp(line, "NO", 3))
		return (1);
	if (!ft_strncmp(line, "SO", 3))
		return (1);
	if (!ft_strncmp(line, "WE", 3))
		return (1);
	if (!ft_strncmp(line, "EA", 3))
		return (1);
	return (0);
}

int	is_color(char *line)
{
	if (!ft_strncmp(line, "F", 2))
		return (1);
	if (!ft_strncmp(line, "C", 2))
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
