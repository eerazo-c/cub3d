/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <elerazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:52:08 by elerazo-          #+#    #+#             */
/*   Updated: 2026/01/19 21:17:45 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	exist_obj(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W' ) 
				&& s[i] != '1' && s[i] != '0' && s[i] != '\n')
			ft_error_fd("ERROR: mapa no exist obj", 1);
		i++;
	}
	return (1);
}
