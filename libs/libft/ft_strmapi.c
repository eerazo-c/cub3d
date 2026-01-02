/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:01:01 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/01 03:56:03 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*len_s;
	size_t	i;

	i = 0;
	len_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (len_s == (NULL))
		return (NULL);
	while (s[i] != '\0')
	{
		len_s[i] = f(i, (s[i]));
		i++;
	}
	len_s[i] = '\0';
	return (len_s);
}
