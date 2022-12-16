/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 09:26:34 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"
# include "mlx.h"
# include "stdio.h"
# include "time.h"
# define WINDOW_WIDHT 1920
# define WINDOW_HEIGHT 1080

// ********************************* estruktura ********************************

typedef struct s_img
{
	void	*Horma;
	void	*Lurra;
	void	*Atea;
	void	*Objeto;
	void	*Coleccionable;
	void	*Robot[2];
	void	*enemy[2];
	void	*end[2];
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*map;
	int		len;
	t_img	img;
}				t_data;

// ********************************* make_move.c ***************************
void	make_ground(t_data data, t_img img);
void	make_corner(t_data data, t_img img);
void	make_obj(t_data data, t_img img);
int		are_there_coins(t_data *data, t_img *img);
int		are_there_door(t_data data, t_img *img);
void	make_enemy(t_data data, t_img img, int a);
void	enemy_move(t_data *data);
int		collition(t_data data, t_img *img, int next, int c);
int		fail(t_data data, t_img *img, int next);
// ********************************* save_data.c ***************************
t_data	map_size(t_data data);
t_img	save_img(t_data data);
// ********************************* make_map.c ***************************
void	make_enemy(t_data data, t_img img, int a);
void	make_obj(t_data data, t_img img);
void	make_corner(t_data data, t_img img);
void	make_ground(t_data data, t_img img);
// ********************************* libft.c ***************************
char	*ft_strjoin(char const *s1, char s2, char const *s3);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	strchng(char *str, int a, int b);
// ********************************* errors.c ***************************
char	*next_step(char *test_map, int pos, int lar);
void	find_out(t_data data);

#endif
