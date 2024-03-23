/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:23 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/22 17:39:58 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	ret_arr = malloc(sizeof(int) * vars->x);
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
		return (return_value);
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

int	pfree_vars(char *str, t_vars *vars, int return_value)
{
	if (str != NULL)
		ft_putstr_fd(str, STDERR_FILENO);
	if (vars == NULL)
		return (return_value);
	if (vars->map != NULL)
	{
		free_int_matrix(vars->map);
		vars->map = NULL;
	}
	return (return_value);
}
