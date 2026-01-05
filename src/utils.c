#include "cub3d.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;
	size_t	i;
	char	*src;
	char	*dst;

	if (new_size == 0)
		return (free(ptr), NULL);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	src = (char *)ptr;
	dst = (char *)new;
	i = 0;
	while (i < old_size && i < new_size)
	{
		dst[i] = src[i];
		i++;
	}
	free(ptr);
	return (new);
}

void	ft_error(char *msg, t_map *game)
{
	(void)game;
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	ft_error_fd(char *msg, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(1);
}

void	ft_error_fd_exvalue(char *msg, int fd, int exitvalue)
{
	ft_putendl_fd(msg, fd);
	exit(exitvalue);
}
