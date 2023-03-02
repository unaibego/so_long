/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:21:31 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/20 10:52:42 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_data *data)
{
	t_img		img;
	static int	count = 0;

	count++;
	img = data->img;
	if (count == 1000 && !are_there_door(*data, &data->img)
		&& !fail(*data, &data->img, 0))
	{
		count = 0;
		make_ground(*data, img);
		make_obj(*data, img);
		make_corner(*data, img);
		make_enemy(*data, img, 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putstr_fd("Error mapa: Cantidad de argumentos\n", 0), 0);
	data.mlx = mlx_init();
	data = map_size(data, argv[1]);
	find_out(data);
	data.win = mlx_new_window(data.mlx, data.height, data.width,
			"Nire lehenengo leihoa");
	data.img = save_img_0(data);
	mlx_loop_hook(data.mlx, handle_no_event, &data);
	mlx_hook(data.win, 2, (1L << 1), moves, &data);
	mlx_key_hook(data.win, key_destroy, &data);
	mlx_hook(data.win, 17, 0, destroy, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
}

int	key_destroy(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}
