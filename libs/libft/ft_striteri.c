/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 03:06:51 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/01 03:17:26 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	s_len;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s_len = ft_strlen(s);
		while (i < s_len)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
