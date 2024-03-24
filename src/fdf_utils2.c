/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:00:08 by aggrigor          #+#    #+#             */
/*   Updated: 2024/03/23 15:34:23 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	*convert_line(t_vars *vars)
{
	int	*ret_arr;
	int	i;

	i = 0;
	ret_arr = malloc(sizeof(int) * vars->x);
	if (ret_arr == NULL)
		return (NULL);
	while (vars->row_splited[i])
	{
		ret_arr[i] = ft_atoi(vars->row_splited[i]);
		i++;
	}
	return (ret_arr);
}

int	my_ternar(bool condition, int val1, int val2)
{
	if (condition)
		return (val1);
	else
		return (val2);
}

void	draw_button_border(t_btn *button, t_vars *vars)
{
	int	pos_x;
	int	pos_y;
	int	size_x;
	int	size_y;

	pos_x = button->pos.x;
	pos_y = button->pos.y;
	size_x = button->size.x;
	size_y = button->size.y;
	draw_line((t_point){pos_x, pos_y},
		(t_point){pos_x + size_x, pos_y}, vars, ORANGE);
	draw_line((t_point){pos_x, pos_y},
		(t_point){pos_x, pos_y + size_y}, vars, ORANGE);
	draw_line((t_point){pos_x + size_x, pos_y},
		(t_point){pos_x + size_x, pos_y + size_y}, vars, ORANGE);
	draw_line((t_point){pos_x, pos_y + size_y},
		(t_point){pos_x + size_x, pos_y + size_y}, vars, ORANGE);
}
