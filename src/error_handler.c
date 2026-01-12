#include "cub3d.h"


void	ft_error(char *msg, t_map game)
{
	(void)game; // ponemos esto porque aun no comprobamos leaks de memoria
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