/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:04:33 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/20 11:03:36 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_ground(t_data data, t_img img)
{
	int		i;
	int		j;

	i = 0;
	while (i < data.height)
	{
		j = 0;
		while (j < data.width)
		{
			mlx_put_image_to_window(data.mlx, data.win, img.lurra, i, j);
			j = j + 32;
		}
		i = i + 32;
	}
}

void	make_corner(t_data data, t_img img)
{
	int	i;

	i = 0;
	while (i < data.height)
	{	
		mlx_put_image_to_window(data.mlx, data.win, img.horma, i, 0);
		mlx_put_image_to_window(data.mlx, data.win,
			img.horma, i, data.width - 64);
		i = i + 64;
	}
	i = 0;
	while (i < data.width)
	{	
		mlx_put_image_to_window(data.mlx, data.win, img.horma, 0, i);
		mlx_put_image_to_window(data.mlx, data.win,
			img.horma, data.height - 64, i);
		i = i + 64;
	}
	show_info(data);
}

void	make_obj(t_data data, t_img img)
{
	int	i;

	i = (data.height + 64);
	while (i < (data.height + 64) * (data.width - 64) / 64)
	{
		if (data.map[i / 64] == '1' && (i % (data.height + 64)) != 0
			&& (i % (data.height + 64)) != (data.height - 64))
			mlx_put_image_to_window(data.mlx, data.win, img.objeto,
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		if (data.map[i / 64] == 'P')
			mlx_put_image_to_window(data.mlx, data.win, img.robot[0],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		if (data.map[i / 64] == 'A')
			mlx_put_image_to_window(data.mlx, data.win, img.robot[1],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		if (data.map[i / 64] == 'C')
			mlx_put_image_to_window(data.mlx, data.win, img.coleccionable,
				i % (data.height + 64) + 8, (i / (data.height + 64) * 64) + 16);
		if (data.map[i / 64] == 'E')
			mlx_put_image_to_window(data.mlx, data.win, img.atea,
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
		i = i + 64;
	}
}

void	make_enemy(t_data data, t_img img, int a)
{
	int	i;

	i = (data.height + 64);
	while (i < (data.height + 64) * (data.width - 64) / 64)
	{
		if (data.map[i / 64] == 'W')
		{
			mlx_put_image_to_window(data.mlx, data.win, img.enemy[0],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
			if (a)
				data.map[i / 64] = 'w';
		}
		else if (data.map[i / 64] == 'w')
		{
			mlx_put_image_to_window(data.mlx, data.win, img.enemy[1],
				(i % (data.height + 64)), (i / (data.height + 64) * 64));
			if (a)
				data.map[i / 64] = 'W';
		}
		i = i + 64;
	}
}

void	show_info(t_data data)
{
	mlx_string_put(data.mlx, data.win, 80, 30, 0x00000000, "MOVES");
	mlx_string_put(data.mlx, data.win, 90, 50, 0x00000000, ft_itoa(data.move));
}
