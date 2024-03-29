/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidebar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:40:12 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 14:56:42 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	add_color_buttons(t_vars *vars)
{
	vars->buttons[9] = (t_btn){{1, 530}, {200 - 1, 30}, reverse_gradient,
		"Reverse gradient"};
	vars->buttons[10] = (t_btn){{1, 560}, {200 - 1, 30}, color_preset_1,
		"Preset 1"};
	vars->buttons[11] = (t_btn){{1, 590}, {200 - 1, 30}, color_preset_2,
		"Preset 2"};
	vars->buttons[12] = (t_btn){{1, 620}, {200 - 1, 30}, color_preset_3,
		"Preset 3"};
	vars->buttons[13] = (t_btn){{1, 650}, {200 - 1, 30}, color_preset_4,
		"Preset 4"};
	vars->buttons[14] = (t_btn){{1, 680}, {200 - 1, 30}, color_preset_5,
		"Preset 5"};
}

void	add_buttons(t_vars *vars)
{
	vars->buttons[0] = (t_btn){{1, 500}, {100 - 1, 30}, zoom_in, "Zoom in"};
	vars->buttons[1] = (t_btn){{100, 500}, {100, 30}, zoom_out, "Zoom out"};
	vars->buttons[2] = (t_btn){{1, 710}, {200 - 1, 30}, reset_map,
		"Reset Position"};
	vars->buttons[3] = (t_btn){{1, 740}, {200 - 1, 30}, top_view, "Top View"};
	vars->buttons[4] = (t_btn){{1, 770}, {200 - 1, 30}, left_view,
		"Left View"};
	vars->buttons[5] = (t_btn){{1, 800}, {200 - 1, 30}, perspective_view,
		"Perspective"};
	vars->buttons[6] = (t_btn){{1, 830}, {200 - 1, 30}, z_zooming_up, "Up"};
	vars->buttons[7] = (t_btn){{1, 860}, {200 - 1, 30}, z_zooming_down,
		"Down"};
	vars->buttons[8] = (t_btn){{1, 890}, {200 - 1, 30}, motion_effect,
		"Motion ON/REV/OFF"};
	add_color_buttons(vars);
	vars->buttons[15] = (t_btn){{0, 0}, {100, 50}, NULL, NULL};
	vars->buttons_cnt = 15;
}

void	draw_buttons(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->buttons_cnt)
	{
		draw_button_border(&vars->buttons[i], vars);
		i++;
	}
}

void	draw_sidebar(t_vars *vars)
{
	draw_sidebar_background(vars);
	draw_buttons(vars);
}
