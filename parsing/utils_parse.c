/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:13:16 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 13:56:31 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

///Comparing the position (x, y) with positions saved in savex and savey
t_bool	is_coord(t_mapcheck *mappy, int x, int y)
{
	int	i;

	i = 0;
	while (mappy->savex[i] != -1)
	{
		if (x == (int)mappy->savex[i] && y == (int)mappy->savey[i])
			return (true);
		i ++;
	}
	return (false);
}

//Countpass for main parse
void	count_pass(t_bigdata *data, t_mapcheck *mappy)
{
	mappy->count_pass = 0;
	if (data->ptr.map[mappy->x +1][mappy->y] != '1' && mappy->pass != 's'
			&& !is_coord(mappy, mappy->x +1, mappy->y))
		mappy->count_pass ++;
	if (mappy->y > 0 && data->ptr.map[mappy->x -1][mappy->y] != '1'
			&& mappy->pass != 'w' && !is_coord(mappy, mappy->x -1, mappy->y))
		mappy->count_pass ++;
	if (data->ptr.map[mappy->x][mappy->y +1] != '1' && mappy->pass != 'd'
			&& !is_coord(mappy, mappy->x, mappy->y +1))
		mappy->count_pass ++;
	if (mappy->y > 0 && data->ptr.map[mappy->x][mappy->y -1] != '1'
			&& mappy->pass != 'a' && !is_coord(mappy, mappy->x, mappy->y -1))
		mappy->count_pass ++;
}

//Countpass for obj parse
void	count_pass_obj(t_bigdata *data, t_mapcheck *mappy)
{
	mappy->count_pass = 0;
	if (data->ptr.map[mappy->x +1][mappy->y] != '1'
			&& data->ptr.map[mappy->x +1][mappy->y] != 'E'
			&& mappy->pass != 's' && !is_coord(mappy, mappy->x +1, mappy->y))
		mappy->count_pass ++;
	if (mappy->x > 0 && data->ptr.map[mappy->x -1][mappy->y] != '1'
			&& data->ptr.map[mappy->x -1][mappy->y] != 'E'
			&& mappy->pass != 'w' && !is_coord(mappy, mappy->x -1, mappy->y))
		mappy->count_pass ++;
	if (data->ptr.map[mappy->x][mappy->y +1] != '1'
			&& data->ptr.map[mappy->x][mappy->y +1] != 'E'
			&& mappy->pass != 'd' && !is_coord(mappy, mappy->x, mappy->y +1))
		mappy->count_pass ++;
	if (mappy->y > 0 && data->ptr.map[mappy->x][mappy->y -1] != '1'
			&& data->ptr.map[mappy->x][mappy->y -1] != 'E'
			&& mappy->pass != 'a' && !is_coord(mappy, mappy->x, mappy->y -1))
		mappy->count_pass ++;
}

//is (x,y) a C?
int	is_obj(t_mapcheck *mappy, t_bigdata *data, int count_hp)
{
	if (data->ptr.map[mappy->x][mappy->y] == 'C')
	{
		count_hp --;
		data->ptr.map[mappy->x][mappy->y] = '0';
	}
	return (count_hp);
}

//Malloc for int*
int	*malloc_int(size_t size)
{
	int		*nb;
	size_t	i;

	nb = malloc(size * sizeof(int));
	if (!nb)
		return (0);
	i = 0;
	while (i < size)
	{
		nb[i] = -1;
		i ++;
	}
	return (nb);
}
