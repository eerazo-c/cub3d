/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       #+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:00:30 by eerazo-c          #+#    #+#             */
/*   Updated: 2023/09/22 17:46:17 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	cb;
	size_t	cs;
	size_t	l_small;
	char	*ptr_big;

	cb = 0;
	ptr_big = (char *)big;
	l_small = ft_strlen(small);
	if (big == small || l_small == 0)
		return (ptr_big);
	while (ptr_big[cb] != '\0' && cb < len)
	{
		cs = 0;
		while (ptr_big[cb + cs] != '\0' && small[cs] != '\0'
			&& ptr_big[cb + cs] == small[cs] && cb + cs < len)
			cs++;
		if (cs == l_small)
			return (ptr_big + cb);
		cb++;
	}
	return (0);
}
