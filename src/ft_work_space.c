/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:00:08 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:55:48 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_text_color(t_limlx *mlx, int key)
{
	if (key == 34 && mlx->text == 1)
		mlx->text = 0;
	else if (key == 34 && mlx->text == 0)
		mlx->text = 1;
	else if (key == 8 && mlx->color_o_f == 1)
		mlx->color_o_f = 0;
	else if (key == 8 && mlx->color_o_f == 0)
		mlx->color_o_f = 1;
}

void	ft_zomm(t_limlx *mlx, char n)
{
	if (n == '+')
	{
		mlx->step += 1;
		mlx->a_point->y_start -= mlx->count_h / 2;
		mlx->a_point->x_start -= mlx->count_w / 2;
	}
	else if (n == '-' && mlx->step > 0)
	{
		mlx->step -= 1;
		mlx->a_point->y_start += mlx->count_h / 2;
		mlx->a_point->x_start += mlx->count_w / 2;
	}
}

void	ft_proection(t_limlx *mlx, int key)
{
	if (key == 18)
	{
		ft_start_pos(mlx, mlx->a_point);
		mlx->a_point->angle_rad = 45 * 3.14159265 / 180;
		ft_rot_matrix_x(mlx->a_point, 1);
		mlx->a_point->angle_rad = 5 * 3.14159265 / 180;
		ft_rot_matrix_y(mlx->a_point, -1);
		mlx->a_point->angle_rad = 42 * 3.14159265 / 180;
		ft_rot_matrix_z(mlx->a_point, -1);
	}
	else if (key == 19)
	{
		ft_start_pos(mlx, mlx->a_point);
		mlx->a_point->angle_rad = 90 * 3.14159265 / 180;
		ft_rot_matrix_x(mlx->a_point, 1);
	}
	mlx->a_point->angle_rad = 2 * 3.14159265 / 180;
}

void	ft_move(t_limlx *mlx, int key)
{
	if (key == 123)
		mlx->a_point->x_start -= 10;
	else if (key == 124)
		mlx->a_point->x_start += 10;
	else if (key == 126)
		mlx->a_point->y_start -= 10;
	else if (key == 125)
		mlx->a_point->y_start += 10;
	else if (key == 91)
		ft_rot_matrix_x(mlx->a_point, 1);
	else if (key == 84)
		ft_rot_matrix_x(mlx->a_point, -1);
	else if (key == 86)
		ft_rot_matrix_y(mlx->a_point, -1);
	else if (key == 88)
		ft_rot_matrix_y(mlx->a_point, 1);
	else if (key == 89)
		ft_rot_matrix_z(mlx->a_point, -1);
	else if (key == 92)
		ft_rot_matrix_z(mlx->a_point, 1);
	else if (key == 69)
		ft_zomm(mlx, '+');
	else if (key == 78)
		ft_zomm(mlx, '-');
}

void	ft_text(t_limlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 60, 30, 0xFFFFFF, "MANUAL");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 60, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 80, 0xFFFFFF, "Move = ^ v < >");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 30, 100, 0xFFFFFF, "Iso = 1");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 30, 120, 0xFFFFFF, "Elev = 2");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 140, 0xFFFFFF, "Parallel/Reset = R");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 160, 0xFFFFFF, "Rot X = 8|2");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 180, 0xFFFFFF, "Rot Y = 4|6");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 200, 0xFFFFFF, "Rot Z = 7|9");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 220, 0xFFFFFF, "Height Z = *|/");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 240, 0xFFFFFF, "Zoom = +|-");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 260, 0xFFFFFF, "Music On/Off = M");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 280, 0xFFFFFF, "Manual On/Off = I");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, \
	30, 300, 0xFFFFFF, "Color On/Off = C");
}
