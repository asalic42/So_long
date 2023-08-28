/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:23:43 by asalic            #+#    #+#             */
/*   Updated: 2023/06/23 13:58:40 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Is it the good file ?
t_bool	is_goodfile(char *ber)
{
	int	fd;

	fd = open(ber, O_RDONLY);
	if (fd <= 0)
	{
		perror("Error");
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

int	end_filename(char *ber)
{
	int	i;

	i = 0;
	while (ber && ber[i +1] != '\0')
	{
		i ++;
	}
	return (i);
}

//Is it the good extension ?
t_bool	is_goodext(char *ber)
{
	int	i;

	i = end_filename(ber);
	if (ber[i] == 'r')
		i --;
	else
		return (false);
	if (ber[i] == 'e')
		i --;
	else
		return (false);
	if (ber[i] == 'b')
		i --;
	else
		return (false);
	if (ber[i] == '.')
		return (true);
	else
		return (false);
}

//Global errors
void	error_cases(t_bigdata *data, char *map)
{
	if (!is_long_map(data, map))
	{
		ft_printf("Error: Les contours de la map ne sont pas aux normes\n");
		close_error(data);
	}
	if (!is_onething(data, map))
	{
		ft_printf("Error: Il manque quelque chose dans la map\n");
		close_error(data);
	}
	if (!is_objcollect(*(data), map))
	{
		ft_printf("Error: Les objets ne sont pas tous collectables\n");
		close_error(data);
	}
	if (!is_right_pass(*(data), map))
	{
		ft_printf("Error: Aucun acces a la sortie\n");
		close_error(data);
	}
}

//Global errors files
void	error_files(t_bigdata *data, char *ber)
{
	if (!is_goodfile(ber))
	{
		ft_printf("Error: Mauvais fichier\n");
		close_error(data);
	}
	if (!is_goodext(ber))
	{
		ft_printf("Error: Mauvaise extension\n");
		close_error(data);
	}
}
