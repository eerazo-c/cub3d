#include "cub3d.h"

int	is_texture(char *line)
{
	if (ft_strchr(line, 'N'))
		return (1);
	if (ft_strchr(line, 'S'))
		return (1);
	if (ft_strchr(line, 'W'))
		return (1);
	if (ft_strchr(line, 'E'))
		return (1);
	return (0);
}

int	is_color(char *line)
{
	if (ft_strchr(line, 'F'))
		return (1);
	if (ft_strchr(line, 'C'))
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
