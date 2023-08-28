/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_coreparse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:58:32 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 13:56:38 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Parse Player to all objects
t_bool	is_objcollect(t_bigdata data, char *ber)
{
	t_mapcheck	mappy;
	int			count_hp;

	wheres_player(&mappy, &data, ber);
	count_hp = data.ptr.hp_len;
	mappy.i = 0;
	while (count_hp > 0)
	{
		count_pass_obj(&data, &mappy);
		if (!what_path_obj(&data, &mappy, count_hp))
		{
			free_fct(&data, &mappy);
			return (false);
		}
		count_hp = is_obj(&mappy, &data, count_hp);
	}
	free_fct(&data, &mappy);
	return (true);
}

//Parse Player to Exit
t_bool	is_right_pass(t_bigdata data, char *ber)
{
	t_mapcheck	mappy;

	wheres_player(&mappy, &data, ber);
	mappy.i = 0;
	while (data.ptr.map[mappy.x][mappy.y] != 'E')
	{
		count_pass(&data, &mappy);
		if (!what_path(&data, &mappy))
		{
			free_fct(&data, &mappy);
			return (false);
		}
	}
	free_fct(&data, &mappy);
	return (true);
}

//Free functions of parsing
void	free_fct(t_bigdata *data, t_mapcheck *mappy)
{
	int	i;

	if (mappy->from_pass)
		free(mappy->from_pass);
	if (mappy->cross_pass)
		free(mappy->cross_pass);
	if (mappy->savex)
		free(mappy->savex);
	if (mappy->savey)
		free(mappy->savey);
	i = 0;
	while (data->ptr.map[i])
	{
		free(data->ptr.map[i]);
		i ++;
	}
	free(data->ptr.map);
}
