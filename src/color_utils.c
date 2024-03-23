/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:59:25 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/22 22:47:37 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

unsigned int	trgb_to_uint(t_color *clr, float factor)
{
	return ((unsigned int)((int)(clr->t * factor) << 24)
		| (int)(clr->r * factor) << 16
		| (int)(clr->g * factor) << 8
		| (int)(clr->b * factor));
}

unsigned int	interpolate_color(t_color *start_color,
	t_color *end_color, float t)
{
	t_color	trgb;

	trgb.t = 0;
	trgb.r = (int)start_color->r + (int)((end_color->r - start_color->r) * t);
	trgb.g = (int)start_color->g + (int)((end_color->g - start_color->g) * t);
	trgb.b = (int)start_color->b + (int)((end_color->b - start_color->b) * t);
	return (trgb_to_uint(&trgb, 1.0));
}

unsigned int	get_pixel_color(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	uint_to_trgb(t_color *trgb, unsigned int color)
{
	trgb->t = (color >> 24) & 0xFF;
	trgb->r = (color >> 16) & 0xFF;
	trgb->g = (color >> 8) & 0xFF;
	trgb->b = color & 0xFF;
}

void	set_color(t_color *dest_color, t_color copy_color)
{
	dest_color->t = copy_color.t;
	dest_color->r = copy_color.r;
	dest_color->g = copy_color.g;
	dest_color->b = copy_color.b;
}
