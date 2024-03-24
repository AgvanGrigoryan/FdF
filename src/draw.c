/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:17:57 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 14:50:00 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_map(t_vars *vars, t_line_cords *line, t_ij *ij)
{
	ij->i = 0;
	while (ij->i < vars->y)
	{
		ij->j = 0;
		while (ij->j + 1 < vars->x)
		{
			if (ij->j + 1 < vars->x)
			{
				assign_p1_cords(line, ij->i, ij->j, vars);
				assign_coordinates((t_ij){ij->i, ij->j},
					(t_ij){ij->i, ij->j + 1}, line, vars);
				il(line, vars, (t_ij){ij->i, ij->j}, (t_ij){ij->i, ij->j + 1});
			}
			if (ij->i + 1 < vars->y)
			{
				assign_p1_cords(line, ij->i, ij->j, vars);
				assign_coordinates((t_ij){ij->i, ij->j},
					(t_ij){ij->i + 1, ij->j}, line, vars);
				il(line, vars, (t_ij){ij->i, ij->j}, (t_ij){ij->i + 1, ij->j});
			}
			ij->j++;
		}
		ij->i++;
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
	t_line_cords	line;
	t_ij			ij;

	vars->total_steps = (vars->max_z * vars->field_size);
	my_mlx_image_clear(&vars->img, vars);
	draw_map(vars, &line, &ij);
	draw_sidebar(vars);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.img, 0, 0);
	show_sidebar_content(vars);
	vars->right_click = false;
}
