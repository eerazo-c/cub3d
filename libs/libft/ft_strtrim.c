/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:59:29 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/15 14:32:11 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;
	char	*puntero;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (s1_len > i && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	puntero = (char *)malloc(sizeof(char) * (s1_len - i +1));
	if (!puntero)
		return (NULL);
	ft_memcpy(puntero, s1 + i, s1_len - i);
	puntero[s1_len - i] = '\0';
	return (puntero);
}
