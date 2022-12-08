/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:21:31 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/08 14:06:02 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img	img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_lenght + x * (img.bits_per_pixel / 8)); // dst is the location of the pixel in all Buffer,this buff is a line so we have to calcule which position is in the line according to X and Y dimentions
	*(unsigned int *)dst = color;
}

int	handle_no_event(t_img *img)
{
	int		img_width;
	int		img_height;
	
	

	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight.xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (1).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (2).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (3).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (4).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (5).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (6).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/eye/Flight (7).xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img,  0, 0);
	usleep(100000);
	
		
	
	
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	moves(int keycode, t_img *img)
{
	int		img_width;
	int		img_height;

	printf("hoasdfd: %d\n", keycode);
	if (keycode == 53)
	{
		printf("kaixo mundua");
		mlx_destroy_window(img->mlx, img->win);
	}
	if (keycode == 124)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/floor_1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1]);
		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1] + 16);
		img->pos[0] = img->pos[0] + 16;
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->pos[0], img->pos[1]);
	}
	if (keycode == 123)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/floor_1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1]);
		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1] + 16);
		img->pos[0] = img->pos[0] - 16;
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->pos[0], img->pos[1]);
	}
	if (keycode == 126)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/floor_1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1]);
		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1] + 16);
		img->pos[1] = img->pos[1] - 16;
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->pos[0], img->pos[1]);
	}
	if (keycode == 125)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/floor_1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1]);
		// img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img,  img->pos[0], img->pos[1] + 16);
		img->pos[1] = img->pos[1] + 16;
		img->img = mlx_xpm_file_to_image(img->mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->pos[0], img->pos[1]);
	}
	
	return (0);
}

int	main(void)
{
	t_img	img;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	img.mlx = mlx_init();
	if (img.mlx == NULL)
		return (0);
	img.win = mlx_new_window(img.mlx, WINDOW_WIDHT,  WINDOW_HEIGHT, "Nire lehenengo leihoa");
	// img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(img.mlx, "imagenes/suelo.xpm", &img_width, &img_height);
	while(i < 2000)
	{
		j = 0;
		while (j < 2000)
		{
			mlx_put_image_to_window(img.mlx, img.win, img.img, i, j);
			j = j + 36;
		}
			
			
		i = i + 36;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, j);
	img.img = mlx_xpm_file_to_image(img.mlx, "imagenes/elf_f_run_anim_f1.xpm", &img_width, &img_height);
	img.pos[0] = 0;
	img.pos[1] = 0;
	mlx_put_image_to_window(img.mlx, img.win, img.img, img.pos[0], img.pos[1]);
	if (img.img == NULL)
	{
		printf("mierda");
		return (0);
	}
	mlx_loop_hook(img.mlx, handle_no_event, &img);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	mlx_key_hook(img.win, &moves, &img);
	mlx_loop(img.mlx);
	// mlx_destroy_window(mlx, win);
	// mlx_destroy_display(img.mlx);
	free(img.mlx);
}
