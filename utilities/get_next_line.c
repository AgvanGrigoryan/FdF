/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:17:53 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/14 11:34:43 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = slen_gnl(src);
	if (dstsize == 0)
		return (src_size);
	while ((i < (dstsize - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			read_size;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (!line)
		return (NULL);
	read_size = 1;
	while (read_size > 0)
	{
		if (new_line_finder(buff, &line))
			return (line);
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		buff[read_size] = '\0';
	}
	if (*line && read_size >= 0)
		return (line);
	return (free(line), NULL);
}
