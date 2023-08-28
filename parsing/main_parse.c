/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:09:11 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 13:53:15 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Find Player in the map
void	wheres_player(t_mapcheck *mappy, t_bigdata *data, char *ber)
{
	data->ptr.map = ft_maptab(ber, data);
	mappy->x = 1;
	mappy->y = 1;
	while (data->ptr.map[mappy->x][mappy->y] != 'P')
	{
		if (mappy->y == data->ptr.width -1)
		{
			mappy->y = 1;
			mappy->x ++;
		}
		else
			mappy->y ++;
	}
	mappy->cross_pass = go_malloc(((data->ptr.height * data->ptr.width)
				- (2 * data->ptr.height + 2 * data->ptr.width) + 1));
	mappy->from_pass = go_malloc(((data->ptr.height * data->ptr.width)
				- (2 * data->ptr.height + 2 * data->ptr.width) + 1));
	mappy->savex = malloc_int((data->ptr.height * data->ptr.width)
			- (2 * data->ptr.height + 2 * data->ptr.width - 4));
	mappy->savey = malloc_int((data->ptr.height * data->ptr.width)
			- (2 * data->ptr.height + 2 * data->ptr.width - 4));
	mappy->pass = 0;
}

//Path choose
t_bool	what_path(t_bigdata *data, t_mapcheck *mappy)
{
	if (data->ptr.map[mappy->x +1][mappy->y] != '1' && mappy->pass != 's'
		&& !is_coord(mappy, mappy->x +1, mappy->y))
		look_down(mappy);
	else if (mappy->x > 0 && data->ptr.map[mappy->x -1][mappy->y] != '1'
		&& mappy->pass != 'w' && !is_coord(mappy, mappy->x -1, mappy->y))
		look_up(mappy);
	else if (data->ptr.map[mappy->x][mappy->y +1] != '1' && mappy->pass != 'd'
		&& !is_coord(mappy, mappy->x, mappy->y +1))
		look_right(mappy);
	else if (mappy->y > 0 && data->ptr.map[mappy->x][mappy->y -1] != '1'
		&& mappy->pass != 'a' && !is_coord(mappy, mappy->x, mappy->y -1))
		look_left(mappy);
	else
	{
		if (mappy->count_pass == 0 && mappy->cross_pass[mappy->i] == '\0')
			return (false);
		none_look(mappy, data);
	}
	return (true);
}

//Path choose with objects
t_bool	what_path_obj(t_bigdata *data, t_mapcheck *mappy, int count_hp)
{
	if (data->ptr.map[mappy->x +1][mappy->y] != '1'
		&& data->ptr.map[mappy->x +1][mappy->y] != 'E' && mappy->pass != 's'
		&& !is_coord(mappy, mappy->x +1, mappy->y))
		look_down(mappy);
	else if (mappy->x > 0 && data->ptr.map[mappy->x -1][mappy->y] != '1'
		&& data->ptr.map[mappy->x -1][mappy->y] != 'E' && mappy->pass != 'w'
		&& !is_coord(mappy, mappy->x -1, mappy->y))
		look_up(mappy);
	else if (data->ptr.map[mappy->x][mappy->y +1] != '1'
		&& data->ptr.map[mappy->x][mappy->y +1] != 'E' && mappy->pass != 'd'
		&& !is_coord(mappy, mappy->x, mappy->y +1))
		look_right(mappy);
	else if (mappy->y > 0 && data->ptr.map[mappy->x][mappy->y -1] != '1'
		&& data->ptr.map[mappy->x][mappy->y -1] != 'E' && mappy->pass != 'a'
		&& !is_coord(mappy, mappy->x, mappy->y -1))
		look_left(mappy);
	else
	{
		if (!nothing_here(data, mappy, count_hp))
			return (false);
	}
	return (true);
}

//Continuation of previous function
t_bool	nothing_here(t_bigdata *data, t_mapcheck *mappy, int count_hp)
{
	if (mappy->count_pass == 0 && (mappy->i == 0
			&& mappy->cross_pass[mappy->i] == '\0') && count_hp > 0)
		return (false);
	none_look(mappy, data);
	return (true);
}
