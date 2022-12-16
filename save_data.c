/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:08:48 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 11:08:45 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	save_img(t_data data)
{
	t_img	img;
	int		width;
	int		height;

	img.Coleccionable = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Dogecoin.xpm", &width, &height);
	img.Lurra = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Lurra.xpm", &width, &height);
	img.Atea = mlx_xpm_file_to_image(data.mlx,
			"imagenes/stonksdoor.xpm", &width, &height);
	img.Objeto = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Objeto.xpm", &width, &height);
	img.Robot[0] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Perro/memeperro0.xpm", &width, &height);
	img.Robot[1] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Perro/memeperro1.xpm", &width, &height);
	img.Horma = mlx_xpm_file_to_image(data.mlx,
			"imagenes/wall.xpm", &width, &height);
	img.enemy[0] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Enemy/Dogegun0.xpm", &width, &height);
	img.enemy[1] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Enemy/Dogegun1.xpm", &width, &height);
	img.end[0] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/End/stonks0.xpm", &width, &height);
	img.end[1] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/End/stonks1.xpm", &width, &height);
	return (img);
}

t_data	map_size(t_data data)
{
	int	fd;
	int	len;

	data.line = 0;
	data.map = malloc(sizeof(char) * 100000);
	fd = open("map.txt", O_RDONLY);
	len = read(fd, data.map, 10000000);
	free(data.map);
	close(fd);
	data.map = malloc(sizeof(char) * len + 1);
	fd = open("map.txt", O_RDONLY);
	read(fd, data.map, len);
	data.map[len] = '\0';
	while (data.map[data.line] && data.map[data.line] != '\n')
		data.line++;
	data.width = (len / data.line) * 64;
	data.height = data.line * 64;
	data.line++;
	return (data);

}
