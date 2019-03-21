/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:05:51 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:48:45 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	mul_rot_matrix(t_point *point, double rot_m[3][3])
{
	int		i;
	int		j;
	int		m;
	double	x[3];

	i = -1;
	while (++i < 3)
	{
		x[0] = 0;
		x[1] = 0;
		x[2] = 0;
		j = -1;
		while (++j < 3)
		{
			m = -1;
			while (++m < 3)
				x[m] += point->base_matrix[i][j] * rot_m[j][m];
		}
		point->base_matrix[i][0] = x[0];
		point->base_matrix[i][1] = x[1];
		point->base_matrix[i][2] = x[2];
	}
}

void		ft_rot_matrix_x(t_point *point, int sing)
{
	point->r_matrix_x[0][0] = 1;
	point->r_matrix_x[0][1] = 0;
	point->r_matrix_x[0][2] = 0;
	point->r_matrix_x[1][0] = 0;
	point->r_matrix_x[1][1] = cos(sing * point->angle_rad);
	point->r_matrix_x[1][2] = -sin(sing * point->angle_rad);
	point->r_matrix_x[2][0] = 0;
	point->r_matrix_x[2][1] = sin(sing * point->angle_rad);
	point->r_matrix_x[2][2] = cos(sing * point->angle_rad);
	mul_rot_matrix(point, point->r_matrix_x);
}

void		ft_rot_matrix_y(t_point *point, int sing)
{
	point->r_matrix_y[0][0] = cos(sing * point->angle_rad);
	point->r_matrix_y[0][1] = 0;
	point->r_matrix_y[0][2] = sin(sing * point->angle_rad);
	point->r_matrix_y[1][0] = 0;
	point->r_matrix_y[1][1] = 1;
	point->r_matrix_y[1][2] = 0;
	point->r_matrix_y[2][0] = -sin(sing * point->angle_rad);
	point->r_matrix_y[2][1] = 0;
	point->r_matrix_y[2][2] = cos(sing * point->angle_rad);
	mul_rot_matrix(point, point->r_matrix_y);
}

void		ft_rot_matrix_z(t_point *point, int sing)
{
	point->r_matrix_z[0][0] = cos(sing * point->angle_rad);
	point->r_matrix_z[0][1] = -sin(sing * point->angle_rad);
	point->r_matrix_z[0][2] = 0;
	point->r_matrix_z[1][0] = sin(sing * point->angle_rad);
	point->r_matrix_z[1][1] = cos(sing * point->angle_rad);
	point->r_matrix_z[1][2] = 0;
	point->r_matrix_z[2][0] = 0;
	point->r_matrix_z[2][1] = 0;
	point->r_matrix_z[2][2] = 1;
	mul_rot_matrix(point, point->r_matrix_z);
}

void		ft_ini_base_matrix(t_point *point)
{
	point->base_matrix[0][0] = 1;
	point->base_matrix[1][1] = 1;
	point->base_matrix[2][2] = 1;
	point->base_matrix[0][1] = 0;
	point->base_matrix[0][2] = 0;
	point->base_matrix[1][0] = 0;
	point->base_matrix[1][2] = 0;
	point->base_matrix[2][0] = 0;
	point->base_matrix[2][1] = 0;
}
