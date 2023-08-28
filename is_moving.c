/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:51:05 by asalic            #+#    #+#             */
/*   Updated: 2023/06/15 10:20:34 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Move player in right
void	is_movingd(t_bigdata *data)
{	
	data->ptr.x = 1;
	data->ptr.y = 1;
	find_player(data);
	if (data->ptr.map[data->ptr.x][data->ptr.y + 1] == 'C'
		&& data->ptr.hp_len > 0)
		data->ptr.hp_len --;
	if (data->ptr.map[data->ptr.x][data->ptr.y + 1] == 'E'
		&& data->ptr.hp_len == 0)
	{
		replace_image(data);
		data->ptr.y ++;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
		ft_printf("You won, congratulations !");
		close_wndow(data);
	}
	if (data->ptr.map[data->ptr.x][data->ptr.y + 1] != '1'
		&& data->ptr.map[data->ptr.x][data->ptr.y + 1] != 'E')
	{
		replace_image(data);
		data->ptr.y ++;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
	}
}

//Move player in left
void	is_movinga(t_bigdata *data)
{	
	data->ptr.x = 1;
	data->ptr.y = 1;
	find_player(data);
	if (data->ptr.map[data->ptr.x][data->ptr.y - 1] == 'C'
		&& data->ptr.hp_len > 0)
		data->ptr.hp_len --;
	else if (data->ptr.map[data->ptr.x][data->ptr.y - 1] == 'E'
		&& data->ptr.hp_len == 0)
	{
		replace_image(data);
		data->ptr.y --;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
		ft_printf("You won, congratulations !");
		close_wndow(data);
	}
	if (data->ptr.map[data->ptr.x][data->ptr.y - 1] != '1'
		&& data->ptr.map[data->ptr.x][data->ptr.y - 1] != 'E')
	{
		replace_image(data);
		data->ptr.y --;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
	}
}

//Move player in top
void	is_movingw(t_bigdata *data)
{
	data->ptr.x = 1;
	data->ptr.y = 1;
	find_player(data);
	if (data->ptr.map[data->ptr.x - 1][data->ptr.y] == 'C'
		&& data->ptr.hp_len > 0)
		data->ptr.hp_len --;
	else if (data->ptr.map[data->ptr.x - 1][data->ptr.y] == 'E'
		&& data->ptr.hp_len == 0)
	{
		replace_image(data);
		data->ptr.x --;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
		ft_printf("You won, congratulations !");
		close_wndow(data);
	}
	if (data->ptr.map[data->ptr.x -1][data->ptr.y] != '1'
		&& data->ptr.map[data->ptr.x -1][data->ptr.y] != 'E')
	{
		replace_image(data);
		data->ptr.x --;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
	}
}

//Move player in down
void	is_movings(t_bigdata *data)
{	
	data->ptr.x = 1;
	data->ptr.y = 1;
	find_player(data);
	if (data->ptr.map[data->ptr.x + 1][data->ptr.y] == 'C'
		&& data->ptr.hp_len > 0)
		data->ptr.hp_len --;
	else if (data->ptr.map[data->ptr.x + 1][data->ptr.y] == 'E'
		&& data->ptr.hp_len == 0)
	{
		replace_image(data);
		data->ptr.x ++;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
		ft_printf("You won, congratulations !");
		close_wndow(data);
	}
	if (data->ptr.map[data->ptr.x + 1][data->ptr.y] != '1'
		&& data->ptr.map[data->ptr.x + 1][data->ptr.y] != 'E')
	{
		replace_image(data);
		data->ptr.x ++;
		replace_imagebis(data);
		ft_printf("Count = %d\n", data->image.count);
	}
}
