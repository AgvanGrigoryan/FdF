/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_actions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:47:52 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 14:49:23 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	motion_effect(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	if (vars->motion_effect == 2)
		vars->motion_effect = 0;
	else
		vars->motion_effect += 1;
}

void	z_zooming_up(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	vars->z_zoom += 1;
	vars->max_z += 1;
	vars->total_steps = vars->max_z * vars->field_size;
}

void	z_zooming_down(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	vars->z_zoom -= 1;
	vars->max_z -= 1;
	vars->total_steps = vars->max_z * vars->field_size;
}

void	perspective_view(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	reset_map(vars);
	vars->top_view = false;
}
