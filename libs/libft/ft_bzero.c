/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:53:43 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/09/26 22:22:27 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*puntero;
	size_t	contador;

	puntero = s;
	contador = 0;
	while (contador < n)
	{
		puntero[contador] = '\0';
		contador++;
	}
}
