/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:53:35 by asalic            #+#    #+#             */
/*   Updated: 2023/06/20 13:28:32 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Check if the first line is only made of 1
t_bool	line_one(t_bigdata *data, t_putmap *lenmap)
{
	lenmap->read = read(lenmap->fd, lenmap->buffer, 1);
	while (lenmap->x != data->ptr.width)
	{
		if (lenmap->buffer[0] == '\n')
			lenmap->read = read(lenmap->fd, lenmap->buffer, 1);
		if (lenmap->buffer[0] != '1' || lenmap->x >= data->ptr.width)
		{
			free_longmap(lenmap);
			return (false);
		}
		lenmap->x ++;
		lenmap->read = read(lenmap->fd, lenmap->buffer, 1);
		if (lenmap->x == data->ptr.width && lenmap->buffer[0] != '\n')
		{
			free_longmap(lenmap);
			return (false);
		}
	}
	lenmap->y ++;
	lenmap->x = 0;
	return (true);
}

//error cases of middle line
t_bool	is_toomuch(t_bigdata *data, t_putmap *lenmap)
{
	if (lenmap->buffer[0] == '\n' && lenmap->x != data->ptr.width)
	{
		free_longmap(lenmap);
		return (false);
	}
	if ((lenmap->x == 0 || lenmap->x == data->ptr.width -1)
		&& lenmap->buffer[0] != '1')
	{
		free_longmap(lenmap);
		return (false);
	}
	return (true);
}

//check if in the middle, l and L are only 1
t_bool	middle_lines(t_bigdata *data, t_putmap *lenmap)
{
	while (lenmap->y != data->ptr.height -1)
	{
		lenmap->read = read(lenmap->fd, lenmap->buffer, 1);
		if (!is_toomuch(data, lenmap))
			return (false);
		if (lenmap->x >= data->ptr.width && lenmap->buffer[0] == '\n')
		{
			lenmap->y ++;
			lenmap->x = 0;
		}
		else if (lenmap->x == data->ptr.width && lenmap->buffer[0] != '\n')
		{
			free_longmap(lenmap);
			return (false);
		}
		else
			lenmap->x ++;
	}
	return (true);
}

t_bool	last_toomuch(t_bigdata *data, t_putmap *lenmap)
{
	if (lenmap->buffer[0] != '\n' && lenmap->x == data->ptr.width)
	{
		free_longmap(lenmap);
		return (false);
	}
	if (lenmap->buffer[0] != '1' && lenmap->x != data->ptr.width)
	{
		free_longmap(lenmap);
		return (false);
	}
	if (lenmap->buffer[0] == '\0')
	{
		free_longmap(lenmap);
		return (false);
	}
	return (true);
}

t_bool	last_line(t_bigdata *data, t_putmap *lenmap)
{
	while (read(lenmap->fd, lenmap->buffer, 1) > 0)
	{
		if (lenmap->x <= data->ptr.width)
		{
			if (!last_toomuch(data, lenmap))
				return (false);
		}
		else
		{
			free_longmap(lenmap);
			return (false);
		}
		lenmap->x ++;
	}
	return (true);
}
