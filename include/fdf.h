/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 02:53:10 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:53:20 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# define HEIGHT 1200
# define WIDTH 720

typedef struct		s_limlx
{
	int				count_h;
	int				count_w;
	int				step;
	void			*mlx_ptr;
	void			*mlx_win;
	int				**map;
	struct s_point	*a_point;
	int				first_en;
	int				color;
	int				key;
	int				move[2];
	int				music;
	int				text;
	int				color_o_f;
}					t_limlx;

typedef struct		s_point
{
	int				x_start;
	int				y_start;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				x;
	int				y;
	int				signx;
	int				signy;
	double			dx;
	double			dy;
	double			error;
	double			error2;
	double			cor_x_y_z[3];
	double			base_matrix[3][3];
	double			r_matrix_x[3][3];
	double			r_matrix_y[3][3];
	double			r_matrix_z[3][3];
	double			*ss;
	double			*sx;
	double			angle_rad;
	double			z;
}					t_point;

int					ft_read_map(t_limlx *mlx, char *argv);
void				ft_del_two_char (char ***tmp);
void				ft_draw(t_limlx *mlx, t_point *point);
void				ft_mul_cor_base(t_limlx *mlx, t_point *point, int x, int y);
void				ft_ini_base_matrix(t_point *point);
void				ft_rot_matrix_x(t_point *point, int sing);
void				ft_rot_matrix_y(t_point *point, int sing);
void				ft_rot_matrix_z(t_point *point, int sing);
int					mouse_move(int x, int y, t_limlx *mlx);
int					my_close(void *param);
int					mouse_up(int key, int x, int y, t_limlx *mlx);
int					mouse_put(int key, int x, int y, t_limlx *mlx);
void				ft_zomm(t_limlx *mlx, char n);
void				ft_proection (t_limlx *mlx, int key);
void				ft_move(t_limlx *mlx, int key);
void				ft_start_pos(t_limlx *mlx, t_point *point);
void				ft_get_color(t_limlx *mlx, int i, int j, int x_y);
void				ft_music(int key, t_limlx *mlx);
void				ft_text(t_limlx *mlx);
void				ft_text_color(t_limlx *mlx, int key);
#endif
