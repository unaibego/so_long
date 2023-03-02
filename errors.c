/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:50:37 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/20 10:47:53 by ubegona          ###   ########.fr       */
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
	while (data.map[pos] != 'P')
		pos++;
	test_map = next_step(test_map, pos, data.line);
	pos = 0;
	while (test_map[pos])
	{
		if (test_map[pos] == 'E' && test_map[pos] == 'P'
			&& test_map[pos] == 'C')
		{
			ft_putstr_fd("Error mapa: No hay salida\n", 0);
			exit (0);
		}
		pos++;
	}
	is_rectangle(data);
	error_mapa_char(data, 0, 0);
	is_map_close(data);
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

void	error_mapa_char(t_data data, int countp, int counte)
{
	int	i;

	i = 0;
	while (data.map[i])
	{
		if (data.map[i] != 'P' && data.map[i] != 'C' && data.map[i] != 'E'
			&& data.map[i] != 'W' && data.map[i] != '0'
			&& data.map[i] != '1' && data.map[i] != '\n')
		{
			ft_putstr_fd("Error mapa: Caracteres no validos\n", 0);
			exit (0);
		}
		if (data.map[i] == 'E')
			countp++;
		if (data.map[i] == 'P')
			counte++;
		if (countp == 2 || counte == 2)
		{
			ft_putstr_fd("Error mapa: Caracteres no validos\n", 0);
			exit (0);
		}
		i++;
	}
}

void	is_map_close(t_data data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data.map[len])
		len++;
	while (data.map[i])
	{
		if ((i > (len - data.line) || i < (data.line - 1)
				|| i % data.line == 0 || (i + 2) % data.line == 0)
			&& data.map[i] != '1')
		{
			ft_putstr_fd("Error mapa: No está cerrado\n", 0);
			exit (0);
		}
		i++;
	}
}
