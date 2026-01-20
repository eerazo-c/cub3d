/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:13:56 by elerazo           #+#    #+#             */
/*   Updated: 2026/01/20 17:14:29 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

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
