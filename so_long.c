/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:59:20 by asalic            #+#    #+#             */
/*   Updated: 2023/06/15 10:21:22 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Close and free everything
int	close_wndow(t_bigdata *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->ptr.mlx, data->ptr.wndow);
	ft_printf("La fenetre se ferme.");
	while (data->ptr.map[i])
	{
		free (data->ptr.map[i]);
		i++;
	}
	if (data->image.player)
		mlx_destroy_image(data->ptr.mlx, data->image.player);
	if (data->image.sea)
		mlx_destroy_image(data->ptr.mlx, data->image.sea);
	if (data->image.out)
		mlx_destroy_image(data->ptr.mlx, data->image.out);
	if (data->image.stone)
		mlx_destroy_image(data->ptr.mlx, data->image.stone);
	if (data->image.obj)
		mlx_destroy_image(data->ptr.mlx, data->image.obj);
	mlx_destroy_display(data->ptr.mlx);
	free(data->ptr.map);
	free(data->ptr.mlx);
	exit (EXIT_FAILURE);
}

//Close in case of error
void	close_error(t_bigdata *data)
{
	mlx_destroy_display(data->ptr.mlx);
	free(data->ptr.mlx);
	exit (EXIT_FAILURE);
}

//Which key is touch
int	deal_key(int keycode, t_bigdata *data)
{
	if (keycode == XK_Escape)
		close_wndow(data);
	if (keycode == XK_a || keycode == XK_Left)
		is_movinga(data);
	if (keycode == XK_d || keycode == XK_Right)
		is_movingd(data);
	if (keycode == XK_w || keycode == XK_Up)
		is_movingw(data);
	if (keycode == XK_s || keycode == XK_Down)
		is_movings(data);
	return (1);
}

//Main core
int	main(int argc, char **argv)
{
	t_bigdata	data;

	if (argc != 2)
		return (0);
	data.ptr.mlx = mlx_init();
	if (data.ptr.mlx == NULL)
		return (0);
	error_files(&data, argv[1]);
	data.ptr.width = countmap_x(argv[1], &data);
	data.ptr.height = countmap_y(argv[1], &data);
	error_cases(&data, argv[1]);
	data.ptr.map = ft_maptab(argv[1], &data);
	data.ptr.wndow = mlx_new_window(data.ptr.mlx, data.ptr.width * 32,
			data.ptr.height * 32, "so_long");
	if (data.ptr.wndow == NULL)
	{
		free(data.ptr.mlx);
		return (0);
	}
	img_create(&data);
	mlx_hook(data.ptr.wndow, 2, 1L << 0, deal_key, &data);
	mlx_hook(data.ptr.wndow, 17, 0, close_wndow, &data);
	mlx_loop(data.ptr.mlx);
	close_wndow(&data);
	return (0);
}
