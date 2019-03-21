/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:41:17 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:46:55 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void		ft_map_zero(t_limlx *mlx, int count_w)
{
	int i;

	i = 0;
	while (i <= count_w)
	{
		mlx->map[i] = NULL;
		i++;
	}
}

static int		ft_count_h(char *argv, t_limlx *mlx)
{
	int		fd;
	char	buf;
	int		count_h;

	count_h = 0;
	if ((fd = open(argv, O_RDONLY)) < 0 || read(fd, &buf, 0) < 0)
	{
		close(fd);
		return (0);
	}
	while (read(fd, &buf, 1) == 1)
	{
		if (buf == '\n')
			count_h++;
	}
	if (count_h < 1)
		return (0);
	mlx->map = (int **)malloc(sizeof(int *) * count_h + 1);
	ft_map_zero(mlx, count_h);
	close(fd);
	return (count_h);
}

static int		ft_count_w(t_limlx *mlx, char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == '-' || (line[i] >= '0' && line[i] <= '9')) \
			&& (i == 0 || line[i - 1] == ' '))
			count++;
		i++;
	}
	if (mlx->count_w != -1 && count != mlx->count_w)
		return (1);
	else if (mlx->count_w == -1)
		mlx->count_w = count;
	return (0);
}

static int		ft_to_int(t_limlx *mlx, char **tmp, int i)
{
	int j;

	j = 0;
	if ((mlx->map[i] = malloc(sizeof(int) * mlx->count_w)) == NULL)
		return (1);
	while (j < mlx->count_w)
	{
		if ((mlx->map[i][j] = ft_atoi(tmp[j])) > 1000)
		{
			mlx->map[i][j] = 1000;
		}
		j++;
	}
	return (0);
}

int				ft_read_map(t_limlx *mlx, char *argv)
{
	int		fd;
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	if ((mlx->count_h = ft_count_h(argv, mlx)) < 1)
		return (1);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		if (ft_count_w(mlx, line) != 0)
		{
			ft_del_two_char(&tmp);
			ft_strdel(&line);
			return (1);
		}
		ft_to_int(mlx, tmp, i);
		ft_del_two_char(&tmp);
		ft_strdel(&line);
		i++;
	}
	return (0);
}
