/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 02:52:49 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:55:59 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		ft_start_pos(t_limlx *mlx, t_point *point)
{
	point->x_start = 400;
	point->y_start = 300;
	mlx->color = 0xFFFFFF;
	point->angle_rad = 2 * 3.14159265 / 180;
	point->z = 1;
	ft_ini_base_matrix(point);
	mlx->first_en = 1;
	mlx->music = 0;
	mlx->text = 1;
	mlx->color_o_f = 1;
}

int			keyclick(int key, t_limlx *mlx)
{
	if (key == 53)
	{
		if (mlx->music == 1)
			system("killall afplay");
		exit(0);
	}
	if ((key == 69 || key == 78) || (key >= 84 && key <= 126))
		ft_move(mlx, key);
	else if (key == 15)
		ft_start_pos(mlx, mlx->a_point);
	else if (key == 75)
		mlx->a_point->z -= 0.1;
	else if (key == 67)
		mlx->a_point->z += 0.1;
	else if (key == 18 || key == 19)
		ft_proection(mlx, key);
	else if (key == 46)
		ft_music(key, mlx);
	else if (key == 8 || key == 34)
		ft_text_color(mlx, key);
	ft_draw(mlx, mlx->a_point);
	return (0);
}

t_limlx		*first_step(t_point **point)
{
	t_limlx		*mlx;

	if ((*point = (t_point *)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	if ((mlx = (t_limlx *)malloc(sizeof(t_limlx))) == NULL)
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->count_w = -1;
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, "Chegevara");
	mlx->a_point = *point;
	ft_start_pos(mlx, *point);
	return (mlx);
}

int			main(int argc, char **argv)
{
	t_limlx		*mlx;
	t_point		*point;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (0);
	}
	if ((mlx = first_step(&point)) == NULL || ft_read_map(mlx, argv[1]) != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_draw(mlx, point);
	mlx_hook(mlx->mlx_win, 4, 5, mouse_put, mlx);
	mlx_hook(mlx->mlx_win, 5, 5, mouse_up, mlx);
	mlx_hook(mlx->mlx_win, 2, 5, keyclick, mlx);
	mlx_hook(mlx->mlx_win, 6, 5, mouse_move, mlx);
	mlx_hook(mlx->mlx_win, 17, 5, my_close, (void *)0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
