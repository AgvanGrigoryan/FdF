/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:17:57 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 13:23:51 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_line(t_point p1, t_point p2, t_vars *vars, unsigned int color)
{
	t_point	diff;
	t_point	step;
	int		err;
	int		e2;

	diff.x = abs(p1.x - p2.x);
	diff.y = abs(p1.y - p2.y);
	step.x = TERNAR(p1.x < p2.x, 1, -1);
	step.y = TERNAR(p1.y < p2.y, 1, -1);
	err = TERNAR(diff.x > diff.y, diff.x, -diff.y) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		my_mlx_pixel_put(&vars->img, (t_point){p1.x, p1.y}, color);
		e2 = err;
		if (e2 > -diff.x)
		{
			err -= diff.y;
			p1.x += step.x;
		}
		if (e2 < diff.y)
		{
			err += diff.x;
			p1.y += step.y;
		}
	}
}


void	config_line_vars(t_point *diff, t_point *step, int *err, t_line_cords *line)
{
	diff->x = abs(line->p1.x - line->p2.x);
	diff->y = abs(line->p1.y - line->p2.y);
	step->x = TERNAR(line->p1.x < line->p2.x, 1, -1);
	step->y = TERNAR(line->p1.y < line->p2.y, 1, -1);
	*err = TERNAR(diff->x > diff->y, diff->x, -diff->y) / 2;
}

void	proces_line_vars(t_point *diff, t_point *step, int *err, t_line_cords *line)
{
	int	e2;

	e2 = *err;
	if (e2 > -diff->x)
	{
		err -= diff->y;
		line->p1.x += step->x;
	}
	if (e2 < diff->y)
	{
		err += diff->x;
		line->p1.y += step->y;
	}
}

void	draw_iline(t_line_cords *line, t_vars *vars, t_ij ij1, t_ij ij2)
{
	unsigned int color;
	float	t;
	int	current_step;
	int step_step;

		
	t_point	diff;
	t_point	step;
	int		err;
	
	step_step = 0;
	if (vars->map[ij1.i][ij1.j] > vars->map[ij2.i][ij2.j])
		step_step = -1;
	else if (vars->map[ij1.i][ij1.j] < vars->map[ij2.i][ij2.j])
		step_step = 1;
	current_step = vars->map[ij1.i][ij1.j] * vars->field_size;
	
	config_line_vars(&diff, &step, &err, line);
	while (line->p1.x != line->p2.x || line->p1.y != line->p2.y)
	{
		t = current_step / vars->total_steps;
		color = interpolate_color(&vars->start_color, &vars->end_color, t);
		my_mlx_pixel_put(&vars->img, (t_point){line->p1.x, line->p1.y}, color);
		proces_line_vars(&diff, &step, &err, line);
		current_step += step_step;
	}
}

void	draw_horizontal_lines(t_vars *vars)
{
	t_line_cords	line;
	t_ij			ij;

	ij.i = 0;
	while (ij.i < vars->y)
	{
		ij.j = 0;
		while (ij.j + 1 < vars->x)
		{
			assign_p1_cords(&line, ij.i, ij.j, vars);
			assign_coordinates((t_ij){ij.i, ij.j}, (t_ij){ij.i, ij.j + 1},
					&line, vars);
			draw_iline(&line, vars, (t_ij){ij.i, ij.j}, (t_ij){ij.i, ij.j + 1});
			ij.j++;
		}
		ij.i++;
	}
}

void	draw_vertical_lines(t_vars *vars)
{
	t_line_cords	line;
	t_ij			ij;

	ij.i = 0;
	while (ij.i + 1 < vars->y)
	{
		ij.j = 0;
		while (ij.j < vars->x)
		{
			assign_p1_cords(&line, ij.i, ij.j, vars);
			assign_coordinates((t_ij){ij.i, ij.j}, (t_ij){ij.i + 1, ij.j},
					&line, vars);
			draw_iline(&line, vars, (t_ij){ij.i, ij.j}, (t_ij){ij.i + 1, ij.j});
			ij.j++;
		}
		ij.i++;
	}
}
void	my_mlx_pixel_put(t_img *data, t_point pos, unsigned int color)
{
	char	*dst;

	dst = data->addr + (pos.y * data->line_len + pos.x * (data->bpp / 8));
	if (dst >= data->addr && dst < data->addr_end
		&& pos.x * (data->bpp / 8) > 0
		&& pos.x * (data->bpp / 8) < data->line_len)
		*(unsigned int *)dst = color;
}

void	draw(t_vars *vars)
{
	my_mlx_image_clear(&vars->img, vars);
	draw_horizontal_lines(vars);
	draw_vertical_lines(vars);
	draw_sidebar(vars);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
	show_sidebar_content(vars);
	vars->right_click = false;
}