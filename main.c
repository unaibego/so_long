/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:21:31 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/06 20:03:10 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img	img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_lenght + x * (img.bits_per_pixel / 8)); // dst is the location of the pixel in all Buffer,this buff is a line so we have to calcule which position is in the line according to X and Y dimentions
	*(unsigned int *)dst = color;
}

int	handle_no_event(int keysym, void *data)
{
	data = NULL;
	keysym = 0;
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	closes(int keycode, t_img *img)
{
	int i; 
	int j;

	i = keycode * 20;
	printf("hoasdfd: %d\n", keycode);
	my_mlx_pixel_put(*img, keycode, keycode, 0x00E55300);
	if (keycode == 53)
	{
		printf("kaixo mundua");
		mlx_destroy_window(img->mlx, img->win);
	}
	while(i < keycode * 50)
	{
	j = keycode * 20;
		while(j < keycode * 50) // this addres, is the addres to the buffer of every pixel in the image
			my_mlx_pixel_put(*img, i, j++, 0x00E55300);
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_img	img;
	img.mlx = mlx_init();
	if (img.mlx == NULL)
		return (0);
	img.win = mlx_new_window(img.mlx, WINDOW_WIDHT,  WINDOW_HEIGHT, "Nire lehenengo leihoa");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	mlx_key_hook(img.win, &closes, &img);
	mlx_loop(img.mlx);
	// mlx_destroy_window(mlx, win);
	// mlx_destroy_display(img.mlx);
	free(img.mlx);
}
