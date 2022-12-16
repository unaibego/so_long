/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:50:37 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 14:09:48 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*next_step(char *test_map, int pos, int lar)
{
	test_map[pos] = '1';
	if (test_map[pos + 1] && test_map[pos + 1] != '1'
		&& test_map[pos + 1] != '\n')
		next_step(test_map, pos + 1, lar);
	if (test_map[pos - 1] && test_map[pos - 1] != '1'
		&& test_map[pos - 1] != '\n')
		next_step(test_map, pos - 1, lar);
	if (test_map[pos + lar] && test_map[pos + lar] != '1'
		&& test_map[pos + lar] != '\n')
		next_step(test_map, pos + lar, lar);
	if (test_map[pos - lar] && test_map[pos - lar] != '1'
		&& test_map[pos - lar] != '\n' )
		next_step(test_map, pos - lar, lar);
	return (test_map);
}

void	find_out(t_data data)
{
	char	*test_map;
	int		pos;

	pos = 0;
	test_map = ft_strdup(data.map);
	while (data.map[pos] != 'E')
		pos++;
	test_map = next_step(test_map, pos, data.line);
	pos = 0;
	while (test_map[pos])
	{
		if (test_map[pos] == 'P' && test_map[pos] == 'E'
			&& test_map[pos] == 'C')
		{
			ft_putstr_fd("Error mapa: No hay salida\n", 0);
			exit (0);
		}
		pos++;
	}
	is_rectangle(data);
	error_mapa_char(data);
}

void	is_rectangle(t_data data)
{
	int	i;

	i = 0;
	while (data.map[i])
	{
		if ((i + 1) % data.line == 0 && data.map[i] != '\n')
		{
			ft_putstr_fd("Error mapa: No es rectangular\n", 0);
			exit (0);
		}
		i++;
	}
}

void	error_mapa_char(t_data data)
{
	int	i;
	int	countp;
	int	counte;

	i = 0;
	countp = 0;
	counte = 0;
	while (data.map[i])
	{
		if (data.map[i] != 'E' && data.map[i] != 'C' && data.map[i] != 'P'
			&& data.map[i] != 'W' && data.map[i] != '0'
			&& data.map[i] != '1' && data.map[i] != '\n')
		{
			printf("%c\n", data.map[i]);
			ft_putstr_fd("Error mapa: Caracteres no validos\n", 0);
			exit (0);
		}
		if (data.map[i] == 'P')
			countp++;
		if (data.map[i] == 'E')
			counte++;
		if (countp == 2)
		{
			ft_putstr_fd("Error mapa: Caracteres no validos\n", 0);
			exit (0);
		}
		i++;
	}
}
