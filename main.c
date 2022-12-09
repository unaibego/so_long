/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:21:31 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/09 15:02:06 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_img *img)
{
	// int		img_width;
	// int		img_height;
	img = NULL;
	// printf("%s", img->img_Horma[0]);
	

	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (1).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (2).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (3).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (4).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (5).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (6).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (7).xpm", &img_width, &img_height);
	// mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	// usleep(100000);
	
		
	
	
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

// int	moves(int keycode, t_img *img)
// {
// 	int		img_width;
// 	int		img_height;

// 	printf("hoasdfd: %d\n", keycode);
// 	if (keycode == 53)
// 	{
// 		printf("kaixo mundua");
// 		mlx_destroy_window(img->mlx, img->win);
// 	}
// 	if (keycode == 124)
// 	{
// 		img->img_Lurra = mlx_xpm_file_to_image(img->mlx, "imagenes/Lurra.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1]);
// 		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1] + 16);
// 		data->pos[0] = data->pos[0] + 64;
// 		img->img_Robot = mlx_xpm_file_to_image(img->mlx, "imagenes/OrangeRobot1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img, data->pos[0], data->pos[1]);
// 	}
// 	if (keycode == 123)
// 	{
// 		img->img_Lurra = mlx_xpm_file_to_image(img->mlx, "imagenes/Lurra.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1]);
// 		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1] + 16);
// 		data->pos[0] = data->pos[0] - 64;
// 		img->img_Robot = mlx_xpm_file_to_image(img->mlx, "imagenes/OrangeRobot1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img, data->pos[0], data->pos[1]);
// 	}
// 	if (keycode == 126)
// 	{
// 		img->img_Lurra = mlx_xpm_file_to_image(img->mlx, "imagenes/Lurra.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1]);
// 		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1] + 16);
// 		data->pos[1] = data->pos[1] - 64;
// 		img->img_Robot = mlx_xpm_file_to_image(img->mlx, "imagenes/OrangeRobot1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img, data->pos[0], data->pos[1]);
// 	}
// 	if (keycode == 125)
// 	{
// 		img->img_Lurra = mlx_xpm_file_to_image(img->mlx, "imagenes/Lurra.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1]);
// 		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img,  data->pos[0], data->pos[1] + 16);
// 		data->pos[1] = data->pos[1] + 64;
// 		img->img_Robot = mlx_xpm_file_to_image(img->mlx, "imagenes/OrangeRobot1.xpm", &img_width, &img_height);
// 		mlx_put_image_to_window(img->mlx, img->win, img->img, data->pos[0], data->pos[1]);
// 	}
	
// 	return (0);
// }

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
	data.win = mlx_new_window(data.mlx, data.height, data.width, "Nire lehenengo leihoa");
	img = save_img(data);
	make_ground(data, img);
	make_obj(data, img);
	make_corner(data, img);
	data.pos[0] = 16;
	data.pos[1] = 16;
	mlx_put_image_to_window(data.mlx, data.win, img.img_Robot, data.pos[0], data.pos[1]);
	mlx_put_image_to_window(data.mlx, data.win, img.img_Objeto, 64, 128);
	mlx_loop_hook(data.mlx, handle_no_event, &img);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	// mlx_key_hook(data.win, &moves, &img);
	mlx_loop(data.mlx);
	// mlx_destroy_window(mlx, win);
	// mlx_destroy_display(data.mlx);
	free(data.mlx);
}
