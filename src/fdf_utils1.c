/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:23 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 14:59:36 by aggrigor         ###   ########.fr       */
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
