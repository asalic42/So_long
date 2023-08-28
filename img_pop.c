/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:04:26 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 14:02:25 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//load all xpm files
void	load_img(t_bigdata *data)
{
	data->image.player = mlx_xpm_file_to_image(data->ptr.mlx,
			"./sprites/perso.xpm", &data->image.width,
			&data->image.height);
	if (!data->image.player)
		close_wndow(data);
	data->image.sea = mlx_xpm_file_to_image(data->ptr.mlx,
			"./sprites/sea.xpm", &data->image.width,
			&data->image.height);
	if (!data->image.sea)
		close_wndow(data);
	data->image.obj = mlx_xpm_file_to_image(data->ptr.mlx,
			"./sprites/hp.xpm", &data->image.width,
			&data->image.height);
	if (!data->image.obj)
		close_wndow(data);
	data->image.out = mlx_xpm_file_to_image(data->ptr.mlx,
			"./sprites/chest.xpm", &data->image.width,
			&data->image.height);
	if (!data->image.out)
		close_wndow(data);
	data->image.stone = mlx_xpm_file_to_image(data->ptr.mlx,
			"./sprites/stone.xpm", &data->image.width,
			&data->image.height);
	if (!data->image.stone)
		close_wndow(data);
}

//choose the right image 
void	put_img(t_bigdata *data)
{
	if (data->ptr.map[data->x][data->y] == '1')
		data->image.img_ptr = data->image.sea;
	else if (data->ptr.map[data->x][data->y] == 'P')
		data->image.img_ptr = data->image.player;
	else if (data->ptr.map[data->x][data->y] == 'E')
		data->image.img_ptr = data->image.out;
	else if (data->ptr.map[data->x][data->y] == 'C')
		data->image.img_ptr = data->image.obj;
	else
		data->image.img_ptr = data->image.stone;
}

//creation of the image
void	img_create(t_bigdata *data)
{
	data->x = 0;
	data->y = 0;
	data->image.count = 0;
	load_img(data);
	while (data->x + data->y != (data->ptr.width + data->ptr.height -1))
	{
		if (data->y == data->ptr.width)
		{
			data->y = 0;
			data->x ++;
		}
		put_img(data);
		mlx_put_image_to_window(data->ptr.mlx, data->ptr.wndow,
			data->image.img_ptr, 32 * data->y, 32 * data->x);
		data->y ++;
	}
}

char	*go_map(t_putmap *put, t_bigdata *data)
{
	char	*tab;
	int		y;
	char	buf;

	tab = go_malloc(data->ptr.width);
	if (!tab)
		close_wndow(data);
	y = 0;
	put->read = read(put->fd, &buf, 1);
	while (put->read > 0 && buf != '\n')
	{
		tab[y] = buf;
		y ++;
		put->read = read(put->fd, &buf, 1);
	}
	return (tab);
}

//create the map in a char [x][y]
char	**ft_maptab(char *readmap, t_bigdata *data)
{
	t_putmap	put;
	int			x;
	char		**map;

	put.fd = open(readmap, O_RDONLY);
	map = ft_calloc(data->ptr.height * data->ptr.width, sizeof(char *));
	if (!map)
		close_wndow(data);
	x = 0;
	while (x < data->ptr.height)
	{
		map[x] = go_map(&put, data);
		x ++;
	}
	map[x] = NULL;
	close(put.fd);
	return (map);
}
