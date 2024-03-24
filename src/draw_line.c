/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:50:09 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 15:18:07 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	config_line_vars(t_point *diff, t_point *step,
	int *err, t_line_cords *line)
{
	diff->x = abs(line->p1.x - line->p2.x);
	diff->y = abs(line->p1.y - line->p2.y);
	step->x = my_ternar(line->p1.x < line->p2.x, 1, -1);
	step->y = my_ternar(line->p1.y < line->p2.y, 1, -1);
	*err = my_ternar(diff->x > diff->y, diff->x, -diff->y) / 2;
}

void	proces_line_vars(t_point *diff, t_point *step,
	int *err, t_line_cords *line)
{
	int	e2;

	e2 = *err;
	if (e2 > -(diff->x))
	{
		*err -= diff->y;
		line->p1.x += step->x;
	}
	if (e2 < diff->y)
	{
		*err += diff->x;
		line->p1.y += step->y;
	}
}

void	draw_line(t_point p1, t_point p2, t_vars *vars, unsigned int color)
{
	t_point	diff;
	t_point	step;
	int		err;
	int		e2;

	diff.x = abs(p1.x - p2.x);
	diff.y = abs(p1.y - p2.y);
	step.x = my_ternar(p1.x < p2.x, 1, -1);
	step.y = my_ternar(p1.y < p2.y, 1, -1);
	err = my_ternar(diff.x > diff.y, diff.x, -diff.y) / 2;
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

void	il(t_line_cords *line, t_vars *vars, t_ij ij1, t_ij ij2)
{
	float	current_step;
	t_point	diff;
	t_point	step;
	int		err;
	int		step_step;

	current_step = vars->map[ij1.i][ij1.j] * vars->field_size;
	step_step = 1;
	if (vars->map[ij1.i][ij1.j] > vars->map[ij2.i][ij2.j])
		step_step = -1;
	config_line_vars(&diff, &step, &err, line);
	while (line->p1.x != line->p2.x || line->p1.y != line->p2.y)
	{
		my_mlx_pixel_put(&vars->img, (t_point){line->p1.x, line->p1.y},
			interpolate_color(&vars->start_color,
				&vars->end_color, (current_step / vars->total_steps)));
		proces_line_vars(&diff, &step, &err, line);
		current_step += step_step;
	}
}
