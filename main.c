/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:21:31 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 11:51:59 by ubegona          ###   ########.fr       */
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

int	main(void)
{
	t_img	img;
	t_data	data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	data = map_size(data);
	find_out(data);
	data.win = mlx_new_window(data.mlx, data.height, data.width,
			"Nire lehenengo leihoa");
	img = save_img(data);
	mlx_loop_hook(data.mlx, handle_no_event, &data);
	data.img = img;
	mlx_hook(data.win, 2, (1L << 1), moves, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
}
