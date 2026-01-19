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

// No hagas nada con esto  hay que hacer el refactor luego
//	o si puedes hacerlo hazlo  es un bucle while i < 5   (son 5 texturas ya que el 0 es la ventana es el buffer de pantalla)
//  cambiar los nombre de las imagenes por las variables de las texturas ya cargadas en el struct game cardinals   que ahi estan los nombres
void	init_imgs(t_map *game)
{
	int	i;
	int	width;
	int	height;

	// Reservar espacio: img[0] será el buffer de pantalla, 1..4 las texturas
	game->imgs = ft_calloc(5, sizeof(t_img_data));
	if (!game->imgs)
		ft_error_fd("ERROR: images allocation failed", 1);

	// 0: buffer de pantalla (nueva imagen en memoria para dibujar antes de mostrar)
	game->imgs[0].img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->imgs[0].img_ptr)
		ft_error_fd("ERROR: mlx_new_image failed", 1);
	game->imgs[0].addr = mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[0].line_length = game->imgs[0].size_l;
	game->imgs[0].width = WIDTH;
	game->imgs[0].height = HEIGHT;

	// Texturas: 1=greystone, 2=wood, 3=purplestone, 4=redbrick
	i = 1;
	game->imgs[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/greystone.xpm", &width, &height);
	if (!game->imgs[i].img_ptr)
		ft_error_fd("ERROR: texture greystone missing", 1);
	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].img_ptr,
			&game->imgs[i].bpp, &game->imgs[i].size_l, &game->imgs[i].endian);
	game->imgs[i].line_length = game->imgs[i].size_l;
	game->imgs[i].width = width;
	game->imgs[i].height = height;

	i = 2;
	game->imgs[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/wood.xpm", &width, &height);
	if (!game->imgs[i].img_ptr)
		ft_error_fd("ERROR: texture wood missing", 1);
	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].img_ptr,
			&game->imgs[i].bpp, &game->imgs[i].size_l, &game->imgs[i].endian);
	game->imgs[i].line_length = game->imgs[i].size_l;
	game->imgs[i].width = width;
	game->imgs[i].height = height;

	i = 3;
	game->imgs[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/purplestone.xpm", &width, &height);
	if (!game->imgs[i].img_ptr)
		ft_error_fd("ERROR: texture purplestone missing", 1);
	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].img_ptr,
			&game->imgs[i].bpp, &game->imgs[i].size_l, &game->imgs[i].endian);
	game->imgs[i].line_length = game->imgs[i].size_l;
	game->imgs[i].width = width;
	game->imgs[i].height = height;

	i = 4;
	game->imgs[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/redbrick.xpm", &width, &height);
	if (!game->imgs[i].img_ptr)
		ft_error_fd("ERROR: texture redbrick missing", 1);
	game->imgs[i].addr = mlx_get_data_addr(game->imgs[i].img_ptr,
			&game->imgs[i].bpp, &game->imgs[i].size_l, &game->imgs[i].endian);
	game->imgs[i].line_length = game->imgs[i].size_l;
	game->imgs[i].width = width;
	game->imgs[i].height = height;
}