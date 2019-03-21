/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:36:49 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:47:00 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	tt_putpixel(t_limlx *mlx, t_point *point)
{
	while (point->x != point->x1 || point->y != point->y1)
	{
		point->error2 = point->error * 2;
		mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, \
					point->x, point->y, mlx->color);
		if (point->error2 > -point->dy)
		{
			point->error -= point->dy;
			point->x += point->signx;
		}
		if (point->error2 < point->dx)
		{
			point->error += point->dx;
			point->y += point->signy;
		}
	}
}

void	ft_draw_line(t_limlx *mlx, t_point *point)
{
	point->signx = point->x0 < point->x1 ? 1 : -1;
	point->signy = point->y0 < point->y1 ? 1 : -1;
	point->x = point->x0;
	point->y = point->y0;
	point->dx = abs(point->x1 - point->x0);
	point->dy = abs(point->y1 - point->y0);
	point->error = point->dx - point->dy;
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, point->x1, point->y1, mlx->color);
	tt_putpixel(mlx, point);
}

void	ft_predraw(t_limlx *mlx, t_point *point)
{
	if (mlx->first_en == 1)
	{
		if (mlx->count_h >= mlx->count_w)
			mlx->step = 350 / mlx->count_h;
		else
			mlx->step = 550 / mlx->count_w;
		mlx->first_en = 0;
	}
	point->x0 = point->x_start;
	point->y0 = point->y_start;
	point->y1 = point->y_start;
	point->x1 = point->x_start;
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	if (mlx->text == 1)
		ft_text(mlx);
}

void	ft_draw_2(t_limlx *mlx, t_point *point, int i, int j)
{
	point->x1 = point->x_start + point->cor_x_y_z[0] * mlx->step;
	point->y1 = point->y_start + point->cor_x_y_z[1] * mlx->step;
	ft_get_color(mlx, i, j, 0);
	if (j != 0)
		ft_draw_line(mlx, point);
	point->x0 = point->x1;
	point->y0 = point->y1;
	if (i > 0)
	{
		point->x1 = point->sx[j];
		point->y0 = point->y1;
		point->y1 = point->ss[j];
		ft_get_color(mlx, i, j, 1);
		ft_draw_line(mlx, point);
	}
	point->x1 = point->x_start + point->cor_x_y_z[0] * mlx->step;
	point->y1 = point->y_start + point->cor_x_y_z[1] * mlx->step;
	point->sx[j] = point->x1;
	point->ss[j] = point->y1;
}

void	ft_draw(t_limlx *mlx, t_point *point)
{
	int i;
	int j;

	ft_predraw(mlx, point);
	if (point->ss == NULL && point->sx == NULL)
	{
		point->ss = malloc(sizeof(double) * mlx->count_w);
		point->sx = malloc(sizeof(double) * mlx->count_w);
	}
	i = -1;
	while (++i < mlx->count_h)
	{
		j = -1;
		while (++j < mlx->count_w)
		{
			ft_mul_cor_base(mlx, point, j, i);
			ft_draw_2(mlx, point, i, j);
		}
	}
}
