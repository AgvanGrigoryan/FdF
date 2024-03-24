/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:38 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 15:37:34 by aggrigor         ###   ########.fr       */
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

void	move_to_start_pos(t_point *point1, t_point *point2, t_vars *vars)
{
	point1->x += vars->start.x;
	point1->y += vars->start.y;
	point2->x += vars->start.x;
	point2->y += vars->start.y;
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
	draw(&vars);
	mlx_mouse_hook(vars.win_ptr, mouse_hook, &vars);
	mlx_hook(vars.win_ptr, ON_KEYDOWN, 0, key_hook, &vars);
	mlx_hook(vars.win_ptr, ON_DESTROY, 0, destroy_window, &vars);
	mlx_loop_hook(vars.mlx_ptr, render_next_frame, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
