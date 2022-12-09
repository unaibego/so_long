/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/09 14:40:50 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
 #include "fcntl.h"
# include "stdlib.h"
# include "mlx.h"
# include "stdio.h"
# include "time.h"
# define WINDOW_WIDHT 1920
# define WINDOW_HEIGHT 1080

// ********************************* estruktura ********************************

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pos[2];
	int		width;
	int		height;
	char	*map;
	int		len;
}				t_data;

typedef struct s_img
{
	void	*img_Horma[8];
	void	*img_Lurra;
	void	*img_Atea;
	void	*img_Objeto;
	void	*img_Coleccionable;
	void	*img_Robot;
}				t_img;




// ********************************* make_map.c ***************************
t_img	save_img();
void	make_ground(t_data data, t_img img);
t_data	map_size(t_data data);
void	make_corner(t_data data, t_img img);
void	make_obj(t_data data, t_img img);

#endif
