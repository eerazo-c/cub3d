/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:36:44 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/27 18:51:31 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*strptr;
	size_t	i;

	strptr = s;
	i = 0;
	while (i < n)
	{
		strptr[i] = c;
		i++;
	}
	return (s);
}
