/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:50:47 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/09/18 22:16:10 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dstmov;
	unsigned char	*srcmov;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dstmov = (unsigned char *)dst;
	srcmov = (unsigned char *)src;
	i = 0;
	if (dstmov > srcmov)
		while (n--)
			dstmov[n] = srcmov[n];
	else
	{
		while (n--)
		{
			dstmov[i] = srcmov[i];
			i++;
		}
	}
	return (dst);
}
