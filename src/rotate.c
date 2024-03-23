/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:20:49 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 11:21:03 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_line_cords *line, int z1, int z2, t_vars *vars)
{
	t_point	prev_p1;
	t_point	prev_p2;

	prev_p1.x = line->p1.x;
	prev_p1.y = line->p1.y;
	prev_p2.x = line->p2.x;
	prev_p2.y = line->p2.y;
	line->p1.x = (prev_p1.x - prev_p1.y) * cos(vars->angle);
	line->p1.y = (prev_p1.x + prev_p1.y) * sin(vars->angle) - z1;
	line->p2.x = (prev_p2.x - prev_p2.y) * cos(vars->angle);
	line->p2.y = (prev_p2.x + prev_p2.y) * sin(vars->angle) - z2;
}

void	rotate_x_axis(t_line_cords *line,
	int *z1, int *z2, t_vars *vars)
{
	int	prev_y1;
	int	prev_y2;

	prev_y1 = line->p1.y;
	prev_y2 = line->p2.y;
	line->p1.y = prev_y1 * cos(vars->x_rotate) + *z1 * sin(vars->x_rotate);
	*z1 = -prev_y1 * sin(vars->x_rotate) + *z1 * cos(vars->x_rotate);
	line->p2.y = prev_y2 * cos(vars->x_rotate) + *z2 * sin(vars->x_rotate);
	*z2 = -prev_y2 * sin(vars->x_rotate) + *z2 * cos(vars->x_rotate);
}

void	rotate_y_axis(t_line_cords *line, int *z1, int *z2, t_vars *vars)
{
	int	prev_x1;
	int	prev_x2;

	prev_x1 = line->p1.x;
	prev_x2 = line->p2.x;
	line->p1.x = prev_x1 * cos(vars->y_rotate) + *z1 * sin(vars->y_rotate);
	*z1 = -prev_x1 * sin(vars->y_rotate) + *z1 * cos(vars->y_rotate);
	line->p2.x = prev_x2 * cos(vars->y_rotate) + *z2 * sin(vars->y_rotate);
	*z2 = -prev_x2 * sin(vars->y_rotate) + *z2 * cos(vars->y_rotate);
}

void	rotate_z_axis(t_line_cords *line, t_vars *vars)
{
	int	prev_x1;
	int	prev_x2;

	prev_x1 = line->p1.x;
	prev_x2 = line->p2.x;
	line->p1.x = prev_x1 * cos(vars->z_rotate)
		- line->p1.y * sin(vars->z_rotate);
	line->p1.y = prev_x1 * sin(vars->z_rotate)
		+ line->p1.y * cos(vars->z_rotate);
	line->p2.x = prev_x2 * cos(vars->z_rotate)
		- line->p2.y * sin(vars->z_rotate);
	line->p2.y = prev_x2 * sin(vars->z_rotate)
		+ line->p2.y * cos(vars->z_rotate);
}

void	z_zooming(t_vars *vars, int *z1, int *z2)
{
	if (*z1 != 0)
		*z1 = (*z1 + vars->z_zoom) * vars->field_size;
	if (*z2 != 0)
		*z2 = (*z2 + vars->z_zoom) * vars->field_size;
}