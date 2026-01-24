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

