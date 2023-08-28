/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:24:11 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 13:58:24 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1[0] == '\0')
		return (- ((unsigned char *)s2)[0]);
	if (s2[0] == '\0')
		return (((unsigned char *)s1)[0]);
	while (s2[i] || s1[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i ++;
	}
	return (0);
}

char	*go_malloc(size_t size)
{
	size_t	i;
	char	*tab;

	tab = malloc((size + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = '\0';
		i ++;
	}
	tab[i] = '\0';
	return (tab);
}

//Count of width
int	countmap_x(char	*mappy, t_bigdata *data)
{
	int			width;
	t_putmap	map;

	map.fd = open(mappy, O_RDONLY);
	if (map.fd == -1)
		count_error(data, &map);
	map.buffer = go_malloc(1);
	if (!map.buffer)
		count_error(data, &map);
	map.read = read(map.fd, map.buffer, 1);
	width = 0;
	while (ft_strcmp(map.buffer, "\n") != 0 && map.read != 0 && map.read != -1)
	{
		if (map.buffer[0] != 'E' && map.buffer[0] != 'P'
			&& map.buffer[0] != 'C' && map.buffer[0] != '0'
			&& map.buffer[0] != '1' && map.buffer[0] != '\n')
			count_error(data, &map);
		width ++;
		map.read = read(map.fd, map.buffer, 1);
	}
	map.read = close(map.fd);
	free(map.buffer);
	return (width);
}

//Count of height
int	countmap_y(char	*mappy, t_bigdata *data)
{
	int			height;
	t_putmap	map;

	map.fd = open(mappy, O_RDONLY);
	if (map.fd == -1)
		count_error(data, &map);
	map.buffer = go_malloc(1);
	if (!map.buffer)
		count_error(data, &map);
	map.read = read(map.fd, map.buffer, 1);
	height = 1;
	while (map.read != 0 && map.read != -1)
	{
		if (map.buffer[0] != 'E' && map.buffer[0] != 'P'
			&& map.buffer[0] != 'C' && map.buffer[0] != '0'
			&& map.buffer[0] != '1' && map.buffer[0] != '\n')
			count_error(data, &map);
		if (ft_strcmp(map.buffer, "\n") == 0)
			height ++;
		map.read = read(map.fd, map.buffer, 1);
	}
	map.read = close(map.fd);
	free(map.buffer);
	return (height);
}

//Error of 
void	count_error(t_bigdata *data, t_putmap *map)
{
	if (map->buffer)
		free(map->buffer);
	if (map->fd != -1)
		map->read = close(map->fd);
	ft_printf("Error : Longueur infinie ou nulle\n");
	close_error(data);
}
