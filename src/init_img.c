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

void	init_texture_no(t_map *game,  int index, int width, int height)
{
	game->imgs[index].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			game->cardinal.no, &width, &height);
	if (!game->imgs[index].img_ptr)
		ft_error_fd("ERROR: texture North missing", 1);
	game->imgs[index].addr = mlx_get_data_addr(game->imgs[index].img_ptr,
			&game->imgs[index].bpp, &game->imgs[index].size_l,
			&game->imgs[index].endian);
	game->imgs[index].line_length = game->imgs[index].size_l;
	game->imgs[index].width = width;
	game->imgs[index].height = height;
}

void	init_texture_so(t_map *game, unsigned int index, int width, int height)
{
	game->imgs[index].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			game->cardinal.so, &width, &height);
	if (!game->imgs[index].img_ptr)
		ft_error_fd("ERROR: texture south missing", 1);
	game->imgs[index].addr = mlx_get_data_addr(game->imgs[index].img_ptr,
			&game->imgs[index].bpp, &game->imgs[index].size_l,
			&game->imgs[index].endian);
	game->imgs[index].line_length = game->imgs[index].size_l;
	game->imgs[index].width = width;
	game->imgs[index].height = height;
}

void	init_texture_we(t_map *game, unsigned int index, int width, int height)
{
	game->imgs[index].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			game->cardinal.we, &width, &height);
	if (!game->imgs[index].img_ptr)
		ft_error_fd("ERROR: texture west missing", 1);
	game->imgs[index].addr = mlx_get_data_addr(game->imgs[index].img_ptr,
			&game->imgs[index].bpp, &game->imgs[index].size_l,
			&game->imgs[index].endian);
	game->imgs[index].line_length = game->imgs[index].size_l;
	game->imgs[index].width = width;
	game->imgs[index].height = height;
}

void	init_texture_ea(t_map *game, unsigned int index, int width, int height)
{
	game->imgs[index].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			game->cardinal.ea, &width, &height);
	if (!game->imgs[index].img_ptr)
		ft_error_fd("ERROR: texture east missing", 1);
	game->imgs[index].addr = mlx_get_data_addr(game->imgs[index].img_ptr,
			&game->imgs[index].bpp, &game->imgs[index].size_l,
			&game->imgs[index].endian);
	game->imgs[index].line_length = game->imgs[index].size_l;
	game->imgs[index].width = width;
	game->imgs[index].height = height;
}

void	init_imgs(t_map *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->imgs = ft_calloc(5, sizeof(t_img_data));
	if (!game->imgs)
		ft_error_fd("ERROR: images allocation failed", 1);

	game->imgs[0].img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->imgs[0].img_ptr)
		ft_error_fd("ERROR: mlx_new_image failed", 1);
	game->imgs[0].addr = mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[0].line_length = game->imgs[0].size_l;
	game->imgs[0].width = WIDTH;
	game->imgs[0].height = HEIGHT;

	printf("Loading NO texture: {%s}\n", game->cardinal.no);  // Debug
	printf("Loading SO texture: {%s}\n", game->cardinal.so);  // Debug
	printf("Loading WE texture: {%s}\n", game->cardinal.we);  // Debug
	printf("Loading EA texture: {%s}\n", game->cardinal.ea);  // Debug
	init_texture_no(game, 1, width, height);
	init_texture_so(game, 2, width, height);
	init_texture_we(game, 3, width, height);
	init_texture_ea(game, 4, width, height);
}
