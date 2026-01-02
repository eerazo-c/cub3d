/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:09:33 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/12/23 02:38:09 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	j;
	size_t	lensrc;
	size_t	i;
	int		totallen;
	size_t	lendst;

	j = 0;
	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size > lendst)
		totallen = lendst + lensrc;
	else
		totallen = lensrc + size;
	j = lendst;
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (totallen);
}
