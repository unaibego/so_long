/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:08:48 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/20 11:28:46 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	save_img_0(t_data data)
{
	t_img	img;
	int		width;
	int		height;

	img.coleccionable = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Dogecoin.xpm", &width, &height);
	img.lurra = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Lurra.xpm", &width, &height);
	img.atea = mlx_xpm_file_to_image(data.mlx,
			"imagenes/stonksdoor.xpm", &width, &height);
	img.objeto = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Objeto.xpm", &width, &height);
	img.robot[0] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Perro/memeperro0.xpm", &width, &height);
	img.robot[1] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Perro/memeperro1.xpm", &width, &height);
	img = save_img_1(data, img);
	if (!img.coleccionable || !img.lurra || !img.atea
		|| !img.objeto || !img.robot[0] || !img.robot[1])
	{
		ft_putstr_fd("Error sprites corruptos \n", 0);
		exit(0);
	}
	return (img);
}

t_img	save_img_1(t_data data, t_img img)
{
	int		width;
	int		height;

	img.horma = mlx_xpm_file_to_image(data.mlx,
			"imagenes/wall.xpm", &width, &height);
	img.enemy[0] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Enemy/Dogegun0.xpm", &width, &height);
	img.enemy[1] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/Enemy/Dogegun1.xpm", &width, &height);
	img.end[0] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/End/stonks0.xpm", &width, &height);
	img.end[1] = mlx_xpm_file_to_image(data.mlx,
			"imagenes/End/stonks1.xpm", &width, &height);
	if (!img.horma || !img.enemy[0] || !img.enemy[1]
		|| !img.end[0] || !img.end[1])
	{
		ft_putstr_fd("Error sprites corruptos \n", 0);
		exit(0);
	}
	return (img);
}

t_data	map_size(t_data data, char *map)
{
	int	fd;
	int	len;

	data.line = 0;
	data.map = malloc(sizeof(char) * 1000);
	fd = open(map, O_RDONLY);
	len = read(fd, data.map, 10000);
	if (fd < 0 || !ft_strnstr(map, ".ber") || len < 15)
	{
		ft_putstr_fd("Error mapa: No se puede abrir\n", 0);
		exit(0);
	}
	free(data.map);
	close(fd);
	data.map = malloc(sizeof(char) * len + 1);
	fd = open(map, O_RDONLY);
	read(fd, data.map, len);
	data.map[len] = '\0';
	while (data.map[data.line] && data.map[data.line] != '\n')
		data.line++;
	data.width = (len / data.line) * 64;
	data.height = data.line * 64;
	data.line++;
	data.move = 0;
	return (data);
}

int	ft_strnstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (needle[0] == '\0')
		return (0);
	while (((char *)haystack)[i])
	{
		j = 0;
		while (((char *)haystack)[i + j] == ((char *)needle)[j]
		&& ((char *)haystack)[i + j])
		{
			if (!((char *)needle)[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
