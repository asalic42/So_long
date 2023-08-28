/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:54:46 by asalic            #+#    #+#             */
/*   Updated: 2023/06/15 10:21:54 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//replace image player to image stone
void	replace_image(t_bigdata *data)
{
	data->ptr.map[data->ptr.x][data->ptr.y] = '0';
	data->image.img_ptr = data->image.stone;
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.wndow,
		data->image.img_ptr, data->ptr.y * 32, data->ptr.x * 32);
}

//replace image with image player
void	replace_imagebis(t_bigdata *data)
{
	data->ptr.map[data->ptr.x][data->ptr.y] = 'P';
	data->image.img_ptr = data->image.player;
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.wndow,
		data->image.img_ptr, data->ptr.y * 32, data->ptr.x * 32);
	data->image.count ++;
}

void	find_player(t_bigdata *data)
{
	while (data->ptr.map[data->ptr.x][data->ptr.y] != 'P')
	{
		if (data->ptr.y == data->ptr.width -1)
		{
			data->ptr.y = 1;
			data->ptr.x ++;
		}
		else
			data->ptr.y ++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
