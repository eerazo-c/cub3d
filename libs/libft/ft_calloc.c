/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:56:40 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/10 15:47:57 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*puntero;

	puntero = malloc(count * size);
	if (puntero == NULL)
		return (NULL);
	ft_bzero (puntero, count * size);
	return (puntero);
}
