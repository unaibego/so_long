/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:18:33 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/09 15:17:34 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	save_img(t_data data)
{
	t_img 	img;
	int		img_width;
	int		img_height;

	printf("kaico;");
	img.img_Robot = mlx_xpm_file_to_image(data.mlx, "imagenes/OrangeRobot1.xpm", &img_width, &img_height);
	img.img_Lurra = mlx_xpm_file_to_image(data.mlx, "imagenes/Lurra.xpm", &img_width, &img_height);
	img.img_Atea = mlx_xpm_file_to_image(data.mlx, "imagenes/Atea.xpm", &img_width, &img_height);
	img.img_Objeto = mlx_xpm_file_to_image(data.mlx, "imagenes/Objeto.xpm", &img_width, &img_height);
	img.img_Coleccionable = mlx_xpm_file_to_image(data.mlx, "imagenes/Colecionable.xpm", &img_width, &img_height);
	img.img_Horma[0] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm00.xpm", &img_width, &img_height);
	img.img_Horma[1] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm01.xpm", &img_width, &img_height);
	img.img_Horma[2] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm02.xpm", &img_width, &img_height);
	img.img_Horma[3] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm10.xpm", &img_width, &img_height);
	img.img_Horma[4] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm12.xpm", &img_width, &img_height);
	img.img_Horma[5] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm20.xpm", &img_width, &img_height);
	img.img_Horma[6] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm21.xpm", &img_width, &img_height);
	img.img_Horma[7] = mlx_xpm_file_to_image(data.mlx, "imagenes/Horma/Horm22.xpm", &img_width, &img_height);
	return (img);
}

t_data	map_size(t_data data)
{
	int		fd;

	data.height = 0;
	data.map = malloc(sizeof(char) * 100000);
	fd = open("map.txt", O_RDONLY);
	data.len = read(fd, data.map, 10000000);
	free(data.map);
	close(fd);
	data.map = malloc(sizeof(char) * data.len);
	fd = open("map.txt", O_RDONLY);
	read(fd, data.map, data.len);
	while(data.map[data.height] && data.map[data.height] != '\n')
		data.height++;
	data.width = (data.len / data.height - 1) * 64;
	data.height = data.height * 64;
	return (data);
	
}

void	make_ground(t_data data, t_img img)
{
	int		i;
	int		j;


	i = 0;
	while(i < data.height)
	{
		j = 0;
		while (j < data.width)
		{
			mlx_put_image_to_window(data.mlx, data.win, img.img_Lurra, i, j);
			j = j + 32;
		}
		i = i + 32;
	}
}

void	make_corner(t_data data, t_img img)
{
	int	i;
	
	i = 0;
	while(i < data.height)
	{	
		mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[6], i, 0);
		mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[1], i, data.width - 32);
		i = i + 32;
	}
	i = 0;
	while(i < data.width)
	{	
		mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[4], 0, i);
		mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[3], data.height - 32, i);
		i = i + 32;
	}
	mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[7], 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[2], 0, data.width - 32);
	mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[5], data.height - 32, 0);
	mlx_put_image_to_window(data.mlx, data.win, img.img_Horma[0], data.height - 32, data.width - 32);
}



void	make_obj(t_data data, t_img img)
{
	int	i;

	i = 0;
	while (i < data.len)
	{
		
		if(data.map[i] == '1')
			mlx_put_image_to_window(data.mlx, data.win, img.img_Objeto, (i * 64 / data.width) * 64, (i * 64 % data.width) * 64);	
		i++;
	}
}
