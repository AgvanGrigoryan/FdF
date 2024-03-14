/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:20:05 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/14 17:54:41 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

int	argc_and_filename_validation(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid arguments count.\n", 2);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strcmp(&(argv[1][len - 4]), ".fdf") != 0)
	{
		ft_putstr_fd("Invalid filename or extention.\n", 2);
		ft_putstr_fd("Usage: ./fdf <name>.fdf\n", 2);
		return (1);
	}
	return (0);
}

int	parsing_first_line(int fd, t_vars *vars)
{
	vars->row = get_next_line(fd);
	if (vars->row == NULL)
		return (pfree("No data found.\n", vars, 1));
	vars->row_splited = ft_split(vars->row, " \t\v\f\r\n");
	if (vars->row_splited == NULL)
		return (pfree("Allocation failed\n", vars, 1));
	vars->x_size = ft_array_len(vars->row_splited);
	if (vars->x_size == 0)
		return (pfree("Invalid map size\n", vars, 1));
	vars->y_size = 1;
	vars->map = malloc(sizeof(int *) * (vars->y_size + 1));
	if (vars->map == NULL)
		return (pfree("Allocation failed\n", vars, 1));
	vars->map[0] = convert_line(vars);
	if (vars->map[0] == NULL)
		return (pfree("Allocation failed\n", vars, 1));
	vars->map[1] = NULL;
	pfree(NULL, vars, 0);
	return (0);
}
int	extend_map(t_vars *vars)
{
	int	i;

	i = 0;
	vars->temp_map = vars->map;
	vars->map = malloc(sizeof(int *) * (vars->y_size + 1));
	if (vars->map == NULL)
		return (1);
	while (i < vars->y_size - 1)
	{
		vars->map[i] = vars->temp_map[i];
		i++;
	}
	free(vars->temp_map);
	return (0);
}

int	parsing_other_lines(int fd, t_vars *vars)
{
	int		row_length;

	while (1)
	{
		vars->row = get_next_line(fd);
		if (vars->row == NULL)
			break ;
		vars->row_splited = ft_split(vars->row, " \t\v\f\r\n");
		if (vars->row_splited == NULL)
			return (pfree("Allocation failed\n", vars, 1));
		row_length = ft_array_len(vars->row_splited);
		if (row_length != vars->x_size)
			return (pfree("Invalid map size\n", vars, 1));
		vars->y_size++;
		if (extend_map(vars) == 1)
			return (pfree("Allocation failed\n", vars, 1));
		vars->map[vars->y_size - 1] = convert_line(vars);
		if (vars->map[vars->y_size - 1] == NULL)
			return (pfree("Allocation failed\n", vars, 1));
		vars->map[vars->y_size] = NULL;
		vars->temp_map = NULL;
		pfree(NULL, vars, 1);
	}
	return (0);
}

int	validation(int argc, char **argv, t_vars *vars)
{
	int	fd;

	vars->row = NULL;
	vars->row_splited = NULL;
	vars->temp_map = NULL;
	if (argc_and_filename_validation(argc, argv) == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (pfree("File opening failed.\n", NULL, 1));
	if (parsing_first_line(fd, vars) == 1
		|| parsing_other_lines(fd, vars) == 1)
	{
		if (vars->map != NULL)
			free_int_matrix(vars->map);
		return (1);
	}
	close(fd);
	return (0);
}
