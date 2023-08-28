/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bord2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:26:55 by asalic            #+#    #+#             */
/*   Updated: 2023/06/20 13:30:55 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Main core for borders' check
t_bool	is_long_map(t_bigdata *data, char *ber)
{
	t_putmap	lenmap;

	if (!init_long(&lenmap, ber))
		return (false);
	if (!line_one(data, &lenmap))
		return (false);
	if (!middle_lines(data, &lenmap))
		return (false);
	if (!last_line(data, &lenmap))
		return (false);
	if (lenmap.x < data->ptr.width)
	{
		free_longmap(&lenmap);
		return (false);
	}
	free_longmap(&lenmap);
	return (true);
}

//Init. of is long map
t_bool	init_long(t_putmap *lenmap, char *ber)
{
	lenmap->x = 0;
	lenmap->y = 0;
	lenmap->buffer = go_malloc(1);
	if (!lenmap->buffer)
	{
		return (false);
	}
	lenmap->fd = open(ber, O_RDONLY);
	return (true);
}

//Free longmap check
void	free_longmap(t_putmap *lenmap)
{
	lenmap->read = close(lenmap->fd);
	free(lenmap->buffer);
}
