/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:25:58 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/14 17:21:54 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_vars
{
	int		**map;
	int		**temp_map;
	int		x_size;
	int		y_size;
	char	*row;
	char	**row_splited;
}	t_vars;

// Functions in ft_putstr_fd.c
void	ft_putstr_fd(char *s, int fd);

// Functions in ft_strlen.c
size_t	ft_strlen(const char *s);

// Functions in ft_strcmp.c
int		ft_strcmp(const char *s1, const char *s2);

// Functions in validation.c
int		validation(int argc, char *argv[], t_vars *vars);

// Functions in ft_split.c
char	**ft_split(char *str, char *charset);

// Functions in ft_atoi.c
int		ft_atoi(const char *str);

// fdf_utils1
void	free_array(char **array);
void	free_int_matrix(int **matrix);
int		ft_array_len(char **array);
int		*convert_line(t_vars *vars);
int		pfree(char *str, t_vars *vars, int return_value);

#endif