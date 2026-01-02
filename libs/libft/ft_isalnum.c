/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:43:23 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/09 13:40:12 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>

int main (int ac, char *av[])
{
	if (ac == 2)
	{
		printf("%d", ft_isalnum(atoi(av[1])));
	}
	write(1, "\n", 1);
}*/
