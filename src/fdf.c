/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:38 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 13:12:04 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#include <stdio.h>

void	my_mlx_image_clear(t_img *data, t_vars *vars)
{
	int	offset;

	offset = 0;
	while (offset < (vars->win_size.y * data->line_len))
	{
		*(data->addr + offset) = 0x0;
		offset++;
	}
}

void	show_map_info(t_vars *vars)
{
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 45, 10, WHITE, "Information");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 40, GREY, "X: ");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 40, 40,
		ORANGE, ft_itoa(vars->start.x));
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 110, 40, GREY, "Y: ");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 130, 40,
		ORANGE, ft_itoa(vars->start.y));
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 60, GREY, "ZOOM: ");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 70, 60,
		ORANGE, ft_itoa(vars->field_size));
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 60, 170, WHITE, "Control");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 200,
		ORANGE, "Zooming: +/-");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 220,
		ORANGE, "X axis: a/d");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 240,
		ORANGE, "Y axis: s/w");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 260,
		ORANGE, "Z axis: scroll");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 35, 460,
		WHITE, "Mouse buttons");
}

void	show_sidebar_content(t_vars *vars)
{
	show_map_info(vars);
	show_buttons_text(vars);
}


void	move_to_start_pos(t_point *point1, t_point *point2, t_vars *vars)
{
	point1->x += vars->start.x;
	point1->y += vars->start.y;
	point2->x += vars->start.x;
	point2->y += vars->start.y;
}

void	assign_coordinates(t_ij p1ij, t_ij p2ij, t_line_cords *line, t_vars *vars)
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

int	render_next_frame(t_vars *vars)
{
	if (vars->motion_effect == 1)
	{
		change_rotate_z(0.01, vars);
		draw(vars);
		vars->progress_engine++;
	}
	else if (vars->motion_effect == 2)
	{
		change_rotate_z(-0.01, vars);
		draw(vars);
		vars->progress_engine++;
	}
	return (0);
}

int	get_max_z(t_vars *vars)
{
	int	y;
	int	x;
	int	max;

	max = vars->map[0][0];
	y = 0;
	while (y < vars->y)
	{
		x = 0;
		while (x < vars->x)
		{
			if (max < vars->map[y][x])
				max = vars->map[y][x];
			x++;
		}
		y++;
	}
	return (max);
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
	vars->total_steps = vars->max_z * vars->field_size;
	vars->field_size = assign_field_size(vars);
	add_buttons(vars);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	init_vars(&vars);
	if (validation(argc, argv, &vars) == 1)
		return (0);
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (pfree_vars("Mlx init failed\n", &vars, 1));
	set_vars(&vars);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.win_size.x,
			vars.win_size.y, argv[1]);
	if (vars.win_ptr == NULL)
		return (pfree_vars("mlx_new_window failed\n", &vars, 1));
	printf("MAX_Z: %d\n", vars.max_z);
	draw(&vars);
	mlx_mouse_hook(vars.win_ptr, mouse_hook, &vars);
	mlx_hook(vars.win_ptr, ON_KEYDOWN, 0, key_hook, &vars);
	mlx_hook(vars.win_ptr, ON_DESTROY, 0, destroy_window, &vars);
	mlx_loop_hook(vars.mlx_ptr, render_next_frame, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
