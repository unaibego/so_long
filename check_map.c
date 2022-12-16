/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:28:08 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 11:13:42 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
