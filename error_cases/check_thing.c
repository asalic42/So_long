/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:47:27 by asalic            #+#    #+#             */
/*   Updated: 2023/06/16 11:24:36 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Checker si la map est valide ou non:
    --> 1 seul Player
    --> 1 seule Exit
    --> au moins 1 Collectible
    --> que des 1 autour de la map
    --> passage valide entre le Player et l'Exit
	--> tous les Collectible doivent etre recuperables
*/

//Forest check: P, E, C, 0 & 1
t_bool	forest(t_mapcheck *map, t_putmap *readmap, t_bigdata *data)
{
	if (readmap->buffer[0] == '\n')
		readmap->read = read(readmap->fd, readmap->buffer, 1);
	if (readmap->buffer[0] == 'P' && map->player == 0)
		map->player ++;
	else if (readmap->buffer[0] == 'P' && map->player > 0)
		return (false);
	if (readmap->buffer[0] == 'E' && map->exit_game == 0)
		map->exit_game ++;
	else if (readmap->buffer[0] == 'E' && map->exit_game > 0)
		return (false);
	else if (readmap->buffer[0] != 'E' && readmap->buffer[0] != 'P'
		&& readmap->buffer[0] != 'C' && readmap->buffer[0] != '0'
		&& readmap->buffer[0] != '1')
		return (false);
	if (readmap->buffer[0] == 'C')
		data->ptr.hp_len ++;
	return (true);
}

//Main verif
t_bool	is_onething(t_bigdata *data, char *ber)
{
	t_mapcheck	map;
	t_putmap	readmap;

	if (!init_things(data, &readmap, &map))
		return (false);
	readmap.fd = open(ber, O_RDONLY);
	readmap.read = read(readmap.fd, readmap.buffer, 1);
	while (map.x != data->ptr.width * 32 * data->ptr.height * 32
		&& readmap.read > 0)
	{
		if (!forest(&map, &readmap, data))
		{
			free_things(&readmap);
			return (false);
		}
		readmap.read = read(readmap.fd, readmap.buffer, 1);
		map.x++;
	}
	if (map.player == 0 || data->ptr.hp_len == 0 || map.exit_game == 0)
	{
		free_things(&readmap);
		return (false);
	}
	free_things(&readmap);
	return (true);
}

t_bool	init_things(t_bigdata *data, t_putmap *readmap, t_mapcheck *map)
{
	map->x = 0;
	map->player = 0;
	data->ptr.hp_len = 0;
	data->ptr.player_count = 0;
	map->exit_game = 0;
	readmap->buffer = go_malloc(1);
	if (!readmap->buffer)
		return (false);
	return (true);
}

void	free_things(t_putmap *readmap)
{
	readmap->read = close(readmap->fd);
	free(readmap->buffer);
}
