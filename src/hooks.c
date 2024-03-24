/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:53:27 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 15:37:28 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	destroy_window(t_vars *vars)
{
	my_mlx_image_clear(&vars->img, vars);
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(pfree_vars("Program closed\n", vars, 0));
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEYCODE)
		destroy_window(vars);
	else if (keycode == LEFT_ARROW_KEYCODE)
		move_start(-10, 0, vars);
	else if (keycode == RIGHT_ARROW_KEYCODE)
		move_start(10, 0, vars);
	else if (keycode == TOP_ARROW_KEYCODE)
		move_start(0, -10, vars);
	else if (keycode == BOTTOM_ARROW_KEYCODE)
		move_start(0, 10, vars);
	else if (keycode == A_KEYCODE)
		change_rotate_x(-0.1, vars);
	else if (keycode == D_KEYCODE)
		change_rotate_x(0.1, vars);
	else if (keycode == S_KEYCODE)
		change_rotate_y(-0.1, vars);
	else if (keycode == W_KEYCODE)
		change_rotate_y(0.1, vars);
	else if (keycode == PLUS_KEYCODE || keycode == NUMPAD_PLUS_KEYCODE)
		zoom_in(vars);
	else if (keycode == MINUS_KEYCODE || keycode == NUMPAD_MINUS_KEYCODE)
		zoom_out(vars);
	if (vars->right_click == true)
		draw(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		change_rotate_z(-0.1, vars);
	else if (button == 5)
		change_rotate_z(0.1, vars);
	else if (button == 1)
		check_button_pressed(x, y, vars);
	if (vars->right_click == true)
		draw(vars);
	return (0);
}

void	check_button_pressed(int x, int y, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->buttons_cnt)
	{
		if ((x > vars->buttons[i].pos.x && y > vars->buttons[i].pos.y)
			&& (x < vars->buttons[i].pos.x + vars->buttons[i].size.x
				&& y < vars->buttons[i].pos.y + vars->buttons[i].size.y))
		{
			(vars->buttons[i].action)(vars);
			vars->right_click = true;
		}
		i++;
	}
}
