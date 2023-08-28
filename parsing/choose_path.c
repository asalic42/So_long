/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:12:28 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 13:57:27 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Go down
void	look_down(t_mapcheck *mappy)
{
	if (mappy->count_pass > 1)
	{
		if (mappy->cross_pass[mappy->i] != '\0')
			mappy->i ++;
		mappy->from_pass[mappy->i] = mappy->pass;
		mappy->cross_pass[mappy->i] = 'S';
		mappy->savex[mappy->i] = mappy->x;
		mappy->savey[mappy->i] = mappy->y;
	}
	mappy->x ++;
	mappy->pass = 'w';
}

//Go up
void	look_up(t_mapcheck *mappy)
{
	if (mappy->count_pass > 1)
	{
		if (mappy->cross_pass[mappy->i] != '\0')
			mappy->i ++;
		mappy->from_pass[mappy->i] = mappy->pass;
		mappy->cross_pass[mappy->i] = 'W';
		mappy->savex[mappy->i] = mappy->x;
		mappy->savey[mappy->i] = mappy->y;
	}
	mappy->x --;
	mappy->pass = 's';
}

//Go right
void	look_right(t_mapcheck *mappy)
{
	if (mappy->count_pass > 1)
	{
		if (mappy->cross_pass[mappy->i] != '\0')
			mappy->i ++;
		mappy->from_pass[mappy->i] = mappy->pass;
		mappy->cross_pass[mappy->i] = 'D';
		mappy->savex[mappy->i] = mappy->x;
		mappy->savey[mappy->i] = mappy->y;
	}
	mappy->y ++;
	mappy->pass = 'a';
}

//Go left
void	look_left(t_mapcheck *mappy)
{
	if (mappy->count_pass > 1)
	{
		if (mappy->cross_pass[mappy->i] != '\0')
			mappy->i ++;
		mappy->from_pass[mappy->i] = mappy->pass;
		mappy->cross_pass[mappy->i] = 'A';
		mappy->savex[mappy->i] = mappy->x;
		mappy->savey[mappy->i] = mappy->y;
	}
	mappy->y --;
	mappy->pass = 'd';
}

//If we go nowhere
void	none_look(t_mapcheck *mappy, t_bigdata *data)
{
	mappy->x = mappy->savex[mappy->i];
	mappy->y = mappy->savey[mappy->i];
	if (mappy->cross_pass[mappy->i] == 'D' || mappy->from_pass[mappy->i] == 'd')
		data->ptr.map[mappy->x][mappy->y +1] = '1';
	if (mappy->cross_pass[mappy->i] == 'A' || mappy->from_pass[mappy->i] == 'a')
		data->ptr.map[mappy->x][mappy->y -1] = '1';
	if (mappy->cross_pass[mappy->i] == 'W' || mappy->from_pass[mappy->i] == 'w')
		data->ptr.map[mappy->x -1][mappy->y] = '1';
	if (mappy->cross_pass[mappy->i] == 'S' || mappy->from_pass[mappy->i] == 's')
		data->ptr.map[mappy->x +1][mappy->y] = '1';
	mappy->savex[mappy->i] = '\0';
	mappy->savey[mappy->i] = '\0';
	mappy->cross_pass[mappy->i] = '\0';
	mappy->pass = mappy->from_pass[mappy->i];
	mappy->from_pass[mappy->i] = '\0';
	if (mappy->i != 0)
		mappy->i --;
}
