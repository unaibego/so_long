/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:18:33 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 11:08:10 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	pos = 0;
	while (data->map[pos] != 'E' && data->map[pos] != 'A')
		pos++;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	if (keycode == 124 && collition(*data, &data->img, pos + 1, 'E'))
		data->map[pos] = '0';
	if (keycode == 123 && collition(*data, &data->img, pos - 1, 'A'))
		data->map[pos] = '0';
	if (keycode == 125 && collition(*data, &data->img, pos + data->line, 'E'))
		data->map[pos] = '0';
	if (keycode == 126 && collition(*data, &data->img, pos - data->line, 'A'))
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

void	enemy_move(t_data *data)
{
	int		pos;
	int		enemies;

	pos = 0;
	enemies = 0;
	while (data->map[pos])
	{
		if (data->map[pos] == 'W' || data->map[pos] == 'w')
			enemies++;
		pos++;
	}
	pos = 0;
	while (enemies != 0)
	{
		while (data->map[pos] != 'W' && data->map[pos] != 'w')
			pos++;
		if ((data->map[pos - 1] == 'E' || data->map[pos + 1] == '0') && collition(*data, &data->img, pos + 1, 'V'))
			data->map[pos] = '0';
		else if ((data->map[pos - 1] == 'E' || data->map[pos + data->line] == '0') && collition(*data, &data->img, pos + data->line, 'V'))
			data->map[pos] = '0';
		else if ((data->map[pos - 1] == 'E' || data->map[pos - data->line] == '0') && collition(*data, &data->img, pos - data->line, 'V'))
			data->map[pos] = '0';
		else if ((data->map[pos - 1] == 'E' || data->map[pos - 1] == '0') && collition(*data, &data->img, pos - 1, 'V'))
			data->map[pos] = '0';
		enemies--;
	}
	strchng(data->map, 'V', 'W');

}

void	strchng(char *str, int a, int b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		i++;
	}
}
