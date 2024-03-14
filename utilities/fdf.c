/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:25:54 by natamazy          #+#    #+#             */
/*   Updated: 2024/03/14 17:56:13 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (validation(argc, argv, &vars) == 1)
	{
		system("leaks fdf");
		return (0);
	}
	for (int i = 0; i < vars.y_size; i++)
	{
		for (int j = 0; j < vars.x_size; j++)
		{
			printf("%d ", vars.map[i][j]);
		}
		printf("\n");
	}
	system("leaks fdf");
}
