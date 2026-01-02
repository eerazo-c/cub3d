/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:27:49 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/11/15 14:30:37 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_calen(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_free(char **puntero)
{
	int	i;

	i = 0;
	while (puntero[i])
	{
		free(puntero[i]);
		i++;
	}
	free (puntero);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**puntero;

	i = 0;
	j = 0;
	puntero = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (puntero == NULL)
		return (NULL);
	while (j < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		puntero[j] = (ft_substr(s, i, ft_calen(s, i, c)));
		if (!puntero [j])
			return (ft_free(puntero));
		i += ft_calen(s, i, c);
		j++;
	}
	puntero[j] = 0;
	return (puntero);
}
