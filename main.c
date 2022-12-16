/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:21:31 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 09:26:29 by ubegona          ###   ########.fr       */
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

int	collition(t_data data, t_img *img, int next, int c)
{
	int			width;
	int			height;
	int static	i;

	if (are_there_door(data, img))
		return (0);
	if (fail(data, img, next))
		return (0);
	if (data.map[next] == '1')
		return (0);
	if (data.map[next] == 'P' && !are_there_coins(&data, img))
	{
		img->Robot[0] = mlx_xpm_file_to_image(data.mlx,
				"imagenes/Perro/memeperro4.xpm", &width, &height);
		img->Robot[1] = mlx_xpm_file_to_image(data.mlx,
				"imagenes/Perro/memeperro5.xpm", &width, &height);
		return (0);
	}
	data.map[next] = c;
	if (c != 'V')
	{
		printf("%d mugimendu\n", i);
		i++;
	}
	return (1);
}

int	moves(int keycode, t_data *data)
{
	int		pos;
	int		lar;

	pos = 0;
	lar = 0;
	while (data->map[pos] != 'E' && data->map[pos] != 'A')
		pos++;
	while (data->map[lar - 1] != '\n')
		lar++;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	if (keycode == 124 && collition(*data, &data->img, pos + 1, 'E'))
		data->map[pos] = '0';
	if (keycode == 123 && collition(*data, &data->img, pos - 1, 'A'))
		data->map[pos] = '0';
	if (keycode == 125 && collition(*data, &data->img, pos + lar, 'E'))
		data->map[pos] = '0';
	if (keycode == 126 && collition(*data, &data->img, pos - lar, 'A'))
		data->map[pos] = '0';
	enemy_move(data);
	are_there_coins(data, &data->img);
	if (are_there_door(*data, &data->img))
		return (0);
	if (fail(*data, &data->img, 0))
		return (0);
	make_ground(*data, data->img);
	make_obj(*data, data->img);
	make_corner(*data, data->img);
	make_enemy(*data, data->img, 0);
	return (0);
}

int	are_there_coins(t_data *data, t_img *img)
{
	int		width;
	int		height;
	int		pos;

	pos = 0;
	while (data->map[pos] && data->map[pos] != 'C')
		pos++;

	if (data->map[pos] != 'C')
	{
		img->Robot[0] = mlx_xpm_file_to_image(data->mlx,
				"imagenes/Perro/memeperro2.xpm", &width, &height);
		img->Robot[1] = mlx_xpm_file_to_image(data->mlx,
				"imagenes/Perro/memeperro3.xpm", &width, &height);
		return (1);
	}
	return (0);
}

int	are_there_door(t_data data, t_img *img)
{
	int		pos;
	int		i;

	pos = 0;
	while (data.map[pos] && data.map[pos] != 'P')
		pos++;
	if (data.map[pos] != 'P')
	{
		i = (data.height + 64);
		while (i < (data.height + 64) * (data.width - 64) / 64)
		{
			mlx_put_image_to_window(data.mlx, data.win, img->end[0],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
			i = i + 64;
		}
		return (1);
	}
	return (0);
}

int	fail(t_data data, t_img *img, int next)
{
	int		i;

	if (data.map[next] == 'W' || data.map[next] == 'w' || data.map[next] == 'J')
	{
		i = (data.height + 64);
		while (i < (data.height + 64) * (data.width - 64) / 64)
		{
			mlx_put_image_to_window(data.mlx, data.win, img->end[1],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
			i = i + 64;
		}
		data.map[0] = 'J';
		return (1);
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
	data.win = mlx_new_window(data.mlx, data.height, data.width, "Nire lehenengo leihoa");
	img = save_img(data);
	mlx_loop_hook(data.mlx, handle_no_event, &data);
	data.img = img;
	mlx_hook(data.win, 2, (1L << 1), moves, &data);
	mlx_loop(data.mlx);
	// mlx_destroy_window(mlx, win);
	// mlx_destroy_display(data->mlx);
	free(data.mlx);
}
