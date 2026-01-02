/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:54:15 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/15 21:05:18 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	int		total_len;
	char	*puntero;

	if (s1 && s2)
	{
		total_len = (ft_strlen(s1) + ft_strlen(s2));
		puntero = malloc(total_len + 1);
		if (puntero == NULL)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			puntero[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
			puntero[i++] = s2[j++];
		puntero[i] = '\0';
		return (puntero);
	}
	return (NULL);
}
