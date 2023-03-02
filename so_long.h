/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:12:11 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/20 11:36:07 by ubegona          ###   ########.fr       */
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

// ********************************* estruktura ********************************

typedef struct s_img
{
	void	*horma;
	void	*lurra;
	void	*atea;
	void	*objeto;
	void	*coleccionable;
	void	*robot[2];
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
	int		line;
	int		move;
	t_img	img;
}				t_data;

// ********************************* make_move.c ***************************
void	enemy_move(t_data *data, int pos, int enemies);
int		collition(t_data *data, t_img *img, int next, int c);
int		moves(int keycode, t_data *data);
// ********************************* save_data.c ***************************
t_data	map_size(t_data data, char *map);
t_img	save_img_0(t_data data);
t_img	save_img_1(t_data data, t_img img);
// ********************************* make_map.c ***************************
void	make_enemy(t_data data, t_img img, int a);
void	make_obj(t_data data, t_img img);
void	make_corner(t_data data, t_img img);
void	make_ground(t_data data, t_img img);
void	show_info(t_data data);
// ********************************* libft.c ***************************
char	*ft_strjoin(char const *s1, char s2, char const *s3);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	strchng(char *str, int a, int b);
void	ft_putstr_fd(char *s, int fd);
int		ft_strnstr(const char *haystack, const char *needle);
// ********************************* errors.c ***************************
char	*next_step(char *test_map, int pos, int lar);
void	find_out(t_data data);
void	is_rectangle(t_data data);
void	error_mapa_char(t_data data, int countp, int counte);
void	is_map_close(t_data data);
// ********************************* check_map.c ***************************
int		fail(t_data data, t_img *img, int next);
int		are_there_coins(t_data *data, t_img *img);
int		are_there_door(t_data data, t_img *img);
// ********************************* main.c.c ***************************
int		destroy(t_data *data);
int		key_destroy(int keycode, t_data *data);
int		main(int argc, char **argv);
int		handle_no_event(t_data *data);
// ********************************* ft_itoa.c ***************************
int		count(int z);
int		calcz(int z, char *p);
char	*ft_itoa(int n);

#endif
