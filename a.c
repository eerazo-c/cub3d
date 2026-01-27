/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:02:14 by sguzman           #+#    #+#             */
/*   Updated: 2026/01/27 17:27:37 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*char	*read_line(int fd)
{
	char	*buffer;
	char	character;
	int		bytes;
	int		index;

	index = 0;
	bytes = read(fd, &character, 1);
	buffer = xmalloc(sizeof(char) * 2);
	while (bytes > 0)
	{
		if (character == '\n')
			break ;
		buffer[index++] = character;
		buffer = xrealloc(buffer, ft_strlen(buffer) + 1, ft_strlen(buffer) + 2);
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (index == 0))
		return (xfree(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}
*/