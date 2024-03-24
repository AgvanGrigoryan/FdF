/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_actions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:01:41 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 14:49:19 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	change_rotate_x(float diff, t_vars *vars)
{
	vars->x_rotate += diff;
	vars->right_click = true;
}

void	change_rotate_y(float diff, t_vars *vars)
{
	vars->y_rotate += diff;
	vars->right_click = true;
}

void	change_rotate_z(float diff, t_vars *vars)
{
	vars->z_rotate += diff;
	vars->right_click = true;
}

void	top_view(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	vars->top_view = true;
}

void	left_view(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	vars->z_rotate = -8.60;
	vars->x_rotate = -6.3;
	vars->y_rotate = 0.60;
	vars->top_view = false;
}
