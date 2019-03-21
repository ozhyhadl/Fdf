/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhyhadl <ozhyhadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:58:50 by ozhyhadl          #+#    #+#             */
/*   Updated: 2019/03/08 13:47:02 by ozhyhadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_del_two_char(char ***tmp)
{
	int i;

	i = 0;
	while ((*tmp)[i] != NULL)
	{
		free((*tmp)[i]);
		i++;
	}
	free(*tmp);
	*tmp = NULL;
}
