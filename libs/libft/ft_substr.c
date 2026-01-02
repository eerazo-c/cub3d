/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:35:42 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/03 14:37:03 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	longitud;
	size_t	i;

	longitud = ft_strlen(s);
	if (start >= longitud || !s)
		len = 0;
	if (len < longitud - start)
		new = malloc (sizeof(char) * (len + 1));
	else
		new = malloc (sizeof(char) * (longitud + 1 - start));
	if ((!new))
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
