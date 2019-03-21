/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:46:15 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:53:41 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int			my_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			mouse_up(int key, int x, int y, t_limlx *mlx)
{
	if (key == 1 || key == 2)
		mlx->key = 0;
	x = 0;
	y = 0;
	return (0);
}

int			mouse_move(int x, int y, t_limlx *mlx)
{
	if (mlx->key == 1 || mlx->key == 2)
	{
		if (x > mlx->move[0] && mlx->key == 1)
			mlx->a_point->x_start += x - mlx->move[0];
		else if (x > mlx->move[0] + 1 && mlx->key == 2)
			ft_rot_matrix_y(mlx->a_point, 1);
		if (x < mlx->move[0] && mlx->key == 1)
			mlx->a_point->x_start += x - mlx->move[0];
		else if (x < mlx->move[0] - 1 && mlx->key == 2)
			ft_rot_matrix_y(mlx->a_point, -1);
		if (y > mlx->move[1] && mlx->key == 1)
			mlx->a_point->y_start += y - mlx->move[1];
		else if (y > mlx->move[1] + 1 && mlx->key == 2)
			ft_rot_matrix_x(mlx->a_point, -1);
		if (y < mlx->move[1] && mlx->key == 1)
			mlx->a_point->y_start += y - mlx->move[1];
		else if (y < mlx->move[1] - 1 && mlx->key == 2)
			ft_rot_matrix_x(mlx->a_point, 1);
		mlx->move[0] = x;
		mlx->move[1] = y;
		ft_draw(mlx, mlx->a_point);
	}
	return (0);
}

int			mouse_put(int key, int x, int y, t_limlx *mlx)
{
	if (key == 1 || key == 2)
	{
		if (key == 1)
			mlx->key = 1;
		else
			mlx->key = 2;
		mlx->move[0] = x;
		mlx->move[1] = y;
	}
	if (key == 5)
		ft_zomm(mlx, '+');
	else if (key == 4)
		ft_zomm(mlx, '-');
	else if (key == 7)
		mlx->a_point->z -= 0.1;
	else if (key == 6)
		mlx->a_point->z += 0.1;
	ft_draw(mlx, mlx->a_point);
	return (0);
}

void		ft_music(int key, t_limlx *mlx)
{
	if (key == 46 && mlx->music == 0)
	{
		system("afplay music.mp3&");
		mlx->music = 1;
	}
	else
	{
		system("killall afplay");
		mlx->music = 0;
	}
}
