/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:18:23 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/06 19:43:17 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	cub_free(char **str)
{
	int i;

	i = 0;
	while (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
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

void	ft_error(char *msg, t_map game)
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
