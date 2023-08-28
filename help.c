/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:10:38 by asalic            #+#    #+#             */
/*   Updated: 2023/06/14 14:18:19 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) s;
	while (i < n)
	{
		ptr[i] = '\0';
		i ++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count == 0 || size == 0)
		return (malloc(0));
	if ((__SIZE_MAX__ / size > count) && size > 0)
	{
		tab = malloc(count * size);
		if (!(tab))
			return (NULL);
		ft_bzero(tab, count * size);
		return (tab);
	}
	return (NULL);
}
