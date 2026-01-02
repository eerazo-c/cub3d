/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:44:35 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/10/01 21:03:40 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_sizeint(long int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_negatives(long int n)
{
	int		i;
	char	*str;

	n = n * -1;
	i = ft_sizeint(n) + 1;
	str = (char *)(malloc(sizeof(char) * i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		n = n * -1;
	while (--i > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	str [i] = '-';
	return (str);
}

char	*ft_positives(long int n)
{
	int		i;
	char	*str;

	i = ft_sizeint(n);
	str = (char *)(malloc(sizeof(char) * i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;

	num = n;
	str = NULL;
	if (num < 0)
		str = ft_negatives(num);
	else if (num >= 0)
		str = ft_positives(num);
	return (str);
}
