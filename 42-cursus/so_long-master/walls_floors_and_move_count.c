/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_floors_and_move_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:02:35 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/13 07:59:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_walls_and_floors(mlx_t *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_file_at(mlx, j, i, "textures/wall.png");
			else
				draw_file_at(mlx, j, i, "textures/floor.png");
			j++;
		}
		i++;
	}
}

void	print_move_count(t_params *params)
{
	ft_printf("Move count: %d\n", params->move_count);
}
