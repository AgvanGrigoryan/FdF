/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:53:08 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/14 17:52:07 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_int_matrix(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*convert_line(t_vars *vars)
{
	int	*ret_arr;
	int	i;

	i = 0;
	ret_arr = malloc(sizeof(int) * vars->x_size);
	if (ret_arr == NULL)
		return (NULL);
	while (vars->row_splited[i])
	{
		ret_arr[i] = ft_atoi(vars->row_splited[i]);
		i++;
	}
	return (ret_arr);
}

int	pfree(char *str, t_vars *vars, int return_value)
{
	if (str != NULL)
		ft_putstr_fd(str, STDERR_FILENO);
	if (vars == NULL)
		return (!return_value);
	if (vars->row != NULL)
	{
		free(vars->row);
		vars->row = NULL;
	}
	if (vars->row_splited != NULL)
	{
		free_array(vars->row_splited);
		vars->row_splited = NULL;
	}
	return (return_value);
}
