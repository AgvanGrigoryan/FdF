/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_presets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:36:44 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/22 22:28:58 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	color_preset_1(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	uint_to_trgb(&vars->start_color, 0x1F4037);
	uint_to_trgb(&vars->end_color, 0x99F2C8);
}

void	color_preset_2(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	uint_to_trgb(&vars->start_color, 0x108DC7);
	uint_to_trgb(&vars->end_color, 0xEF8E38);
}

void	color_preset_3(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	uint_to_trgb(&vars->start_color, 0x6A9113);
	uint_to_trgb(&vars->end_color, 0x141517);
}

void	color_preset_4(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	uint_to_trgb(&vars->start_color, 0x780206);
	uint_to_trgb(&vars->end_color, 0x061161);
}

void	color_preset_5(void *void_vars)
{
	t_vars	*vars;

	vars = (t_vars *)void_vars;
	uint_to_trgb(&vars->start_color, 0xE55D87);
	uint_to_trgb(&vars->end_color, 0x5FC3E4);
}
