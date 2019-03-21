/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:35:15 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:47:07 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_get_color(t_limlx *mlx, int i, int j, int x_y)
{
	if (mlx->color_o_f == 1)
	{
		if (mlx->map[i][j] != 0 && ((x_y == 0 \
			&& j != 0 && mlx->map[i][j - 1] != 0) \
			|| (x_y == 1 && i != 0 && mlx->map[i - 1][j] != 0)))
		{
			if (mlx->map[i][j] * mlx->a_point->z > 0.1)
				mlx->color = 0xb20000;
			else if (mlx->map[i][j] * mlx->a_point->z < -0.1)
				mlx->color = 0x6e42f4;
			else
				mlx->color = 0xFFFFFF;
		}
		else
			mlx->color = 0xFFFFFF;
	}
	else
		mlx->color = 0xFFFFFF;
}

void	ft_mul_cor_base(t_limlx *mlx, t_point *point, int x, int y)
{
	int		i;
	int		j;
	double	cor[3];

	cor[0] = x - (mlx->count_w / 2);
	cor[1] = y - (mlx->count_h / 2);
	if ((cor[2] = mlx->map[y][x]) != 0)
		cor[2] *= point->z;
	point->cor_x_y_z[0] = 0;
	point->cor_x_y_z[1] = 0;
	point->cor_x_y_z[2] = 0;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			point->cor_x_y_z[i] += point->base_matrix[i][j] * cor[j];
	}
	point->cor_x_y_z[0] += mlx->count_w / 2;
	point->cor_x_y_z[1] += mlx->count_h / 2;
}
