/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istorric <istorric@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:01:53 by istorric          #+#    #+#             */
/*   Updated: 2024/02/13 19:01:56 by istorric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	init_imgs(t_map *game)
{
	int		height;
	int		width;

	game->imgs = ft_calloc(sizeof(t_img_data), 5);
	game->imgs[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/greystone.xpm", &width, &height);
	game->imgs[0].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/mossy.xpm", &width, &height);
	game->imgs[1].data = (int *)mlx_get_data_addr(game->imgs[1].img_ptr,
			&game->imgs[1].bpp, &game->imgs[1].size_l, &game->imgs[1].endian);
	game->imgs[2].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/purplestone.xpm", &width, &height);
	game->imgs[2].data = (int *)mlx_get_data_addr(game->imgs[2].img_ptr,
			&game->imgs[2].bpp, &game->imgs[2].size_l, &game->imgs[2].endian);
	game->imgs[3].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/redbrick.xpm", &width, &height);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[3].img_ptr,
			&game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	game->imgs[4].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/wood.xpm", &width, &height);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr,
			&game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
}

int	exist_obj(char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '1' c != '0')
		return (-1);
	return (1);
}
