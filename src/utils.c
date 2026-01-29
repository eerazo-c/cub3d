/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:18:23 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/27 17:36:28 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	cub_free(char **str)
{
	int	i;

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

void	*ft_mem(size_t bytes)
{
	void	*temp;

	temp = malloc(bytes);
	if (!temp)
		ft_error_fd("ERROR: Invalid memory ft_realloc (mem)", 1);
	ft_memset(temp, 0, bytes);
	return (temp);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*temp;
	size_t	copy_size;

	if (new_size == 0)
	{
		free_realloc(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ft_mem(new_size));
	temp = ft_mem(new_size);
	copy_size = old_size;

	if (new_size < old_size)
		copy_size = new_size;
	ft_memcpy(temp, ptr, copy_size);
	free(ptr);
	return (temp);
}

void	free_realloc(void *s)
{
	if (s)
		free(s);
}

void	my_pixel_put(t_map *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = game->imgs[0].addr + (y * game->imgs[0].line_length
			+ x * (game->imgs[0].bpp / 8));
	*(unsigned int *)dst = color;
}
