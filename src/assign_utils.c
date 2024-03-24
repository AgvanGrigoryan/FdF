/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:41 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 14:54:04 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_vars(t_vars *vars)
{
	set_color(&vars->start_color, (t_color){0, 255, 99, 89});
	set_color(&vars->end_color, (t_color){0, 171, 255, 5});
	vars->win_size.x = 2000;
	vars->win_size.y = 1020;
	vars->start.y = (vars->win_size.y / 2);
	vars->start.x = vars->sidebar_width + (vars->win_size.x / 2);
	vars->img.img = mlx_new_image(vars->mlx_ptr,
			vars->win_size.x, vars->win_size.y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	vars->img.addr_end = vars->img.addr +(vars->win_size.y
			* vars->img.line_len);
	vars->angle = 0.523599;
	vars->z_rotate = 0.0;
	vars->x_rotate = 0.0;
	vars->y_rotate = 0.0;
	vars->z_zoom = 0;
	vars->progress_engine = 1;
	vars->sidebar_width = 200;
	vars->top_view = 0;
	vars->motion_effect = 0;
	vars->right_click = false;
	vars->max_z = get_max_z(vars);
	vars->field_size = assign_field_size(vars);
	add_buttons(vars);
}

int	assign_field_size(t_vars *vars)
{
	if (vars->x <= 50 && vars->y <= 50 && vars->max_z <= 50)
		return (30);
	else if (vars->x <= 100 && vars->y <= 100 && vars->max_z <= 100)
		return (15);
	else if (vars->x <= 500 && vars->y <= 500 && vars->max_z <= 500)
		return (10);
	else if (vars->x <= 1000 && vars->y <= 1000 && vars->max_z <= 1000)
		return (5);
	else if (vars->x <= 1200 && vars->y <= 1200 && vars->max_z <= 1200)
		return (2);
	return (1);
}

void	assign_coordinates(t_ij p1ij, t_ij p2ij,
	t_line_cords *line, t_vars *vars)
{
	int		p1_z;
	int		p2_z;

	p1_z = vars->map[p1ij.i][p1ij.j];
	p2_z = vars->map[p2ij.i][p2ij.j];
	if (p2ij.j > p1ij.j)
	{
		line->p2.x = line->p1.x + vars->field_size;
		line->p2.y = line->p1.y;
	}
	else
	{
		line->p2.x = line->p1.x;
		line->p2.y = line->p1.y + vars->field_size;
	}
	z_zooming(vars, &p1_z, &p2_z);
	rotate_x_axis(line, &p1_z, &p2_z, vars);
	rotate_y_axis(line, &p1_z, &p2_z, vars);
	rotate_z_axis(line, vars);
	if (vars->top_view == false)
		isometric(line, p1_z, p2_z, vars);
	move_to_start_pos(&line->p1, &line->p2, vars);
}

void	assign_p1_cords(t_line_cords *line, int i, int j, t_vars *vars)
{
	line->p1.x = j * vars->field_size - ((vars->x * vars->field_size) / 2);
	line->p1.y = i * vars->field_size - ((vars->y * vars->field_size) / 2);
}

void	init_vars(t_vars *vars)
{
	vars->map = NULL;
	vars->temp_map = NULL;
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->row = NULL;
	vars->row_splited = NULL;
}
