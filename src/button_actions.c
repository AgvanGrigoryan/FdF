/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:21 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 15:13:40 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom_in(void *void_vars)
{
	((t_vars *)void_vars)->field_size += 1;
	((t_vars *)void_vars)->right_click = true;
}

void	zoom_out(void *void_vars)
{
	if (((t_vars *)void_vars)->field_size - 1 > 0)
	{
		((t_vars *)void_vars)->field_size -= 1;
		((t_vars *)void_vars)->right_click = true;
	}
}

void	reverse_gradient(void *void_vars)
{
	unsigned int	start_color;
	unsigned int	end_color;
	t_vars			*vars;

	vars = (t_vars *)void_vars;
	start_color = trgb_to_uint(&vars->start_color, 1);
	end_color = trgb_to_uint(&vars->end_color, 1);
	uint_to_trgb(&vars->start_color, end_color);
	uint_to_trgb(&vars->end_color, start_color);
}

void	reset_map(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	vars->start.y = (vars->win_size.y / 2);
	vars->start.x = vars->sidebar_width + (vars->win_size.x / 2);
	vars->field_size = assign_field_size(vars);
	vars->max_z = get_max_z(vars);
	vars->angle = 0.523599;
	vars->z_rotate = 0.0;
	vars->x_rotate = 0.0;
	vars->y_rotate = 0.0;
	vars->right_click = false;
}

void	move_start(int x_diff, int y_diff, t_vars *vars)
{
	vars->start.x += x_diff;
	vars->start.y += y_diff;
	vars->right_click = true;
}
