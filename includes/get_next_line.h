/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:58:14 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/14 11:34:46 by natamazy         ###   ########.fr       */
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
