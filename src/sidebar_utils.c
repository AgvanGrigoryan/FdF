/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidebar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:54:32 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 15:36:23 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	show_map_info2(t_vars *vars)
{
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

void	show_map_info(t_vars *vars)
{
	char	*tmp_str;

	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 45, 10, WHITE, "Information");
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 40, GREY, "X: ");
	tmp_str = ft_itoa(vars->start.x);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 40, 40,
		ORANGE, tmp_str);
	free(tmp_str);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 110, 40, GREY, "Y: ");
	tmp_str = ft_itoa(vars->start.y);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 130, 40,
		ORANGE, tmp_str);
	free(tmp_str);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 20, 60, GREY, "ZOOM: ");
	tmp_str = ft_itoa(vars->field_size);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 70, 60,
		ORANGE, tmp_str);
	free(tmp_str);
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 60, 170, WHITE, "Control");
	show_map_info2(vars);
}

void	show_buttons_text(t_vars *vars)
{
	int	i;
	int	pos_x;
	int	pos_y;

	i = 0;
	while (i < vars->buttons_cnt)
	{
		pos_x = vars->buttons[i].pos.x + 10;
		pos_y = vars->buttons[i].pos.y + 5;
		mlx_string_put(vars->mlx_ptr, vars->win_ptr, pos_x + 1, pos_y,
			WHITE, vars->buttons[i].content);
		i++;
	}
}

void	draw_sidebar_background(t_vars *vars)
{
	t_color			trgb;
	unsigned int	color;
	int				y;
	int				x;

	y = 0;
	while (y < vars->win_size.y)
	{
		x = 0;
		while (x < vars->sidebar_width)
		{
			color = get_pixel_color(&vars->img, x, y);
			uint_to_trgb(&trgb, color);
			color = trgb_to_uint(&trgb, 0.25);
			my_mlx_pixel_put(&vars->img, (t_point){x, y}, color);
			x++;
		}
		y++;
	}
	draw_line((t_point){vars->sidebar_width + 1, 0},
		(t_point){vars->sidebar_width + 1,
		vars->win_size.y}, vars, WHITE);
}

void	show_sidebar_content(t_vars *vars)
{
	show_map_info(vars);
	show_buttons_text(vars);
}
