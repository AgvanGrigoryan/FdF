/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:07 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/14 18:13:10 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2, size_t k);
char	*ft_strchr(const char *s, int c);
size_t	slen_gnl(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*new_line_finder(char *buff, char **line);

#endif
