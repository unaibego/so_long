/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:18:33 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/15 13:37:32 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_data *data)
{
	int		pos;
	int		lar;
	int		enemies;

	pos = 0;
	lar = 0;
	enemies = 0;
	while (data->map[pos])
	{
		if (data->map[pos] == 'W' || data->map[pos] == 'w')
			enemies++;
		pos++;
	}
	pos = 0;
	while (data->map[lar - 1] != '\n')
		lar++;
	while (enemies != 0)
	{
		while (data->map[pos] != 'W' && data->map[pos] != 'w')
			pos++;
		if ((data->map[pos - 1] == 'E' || data->map[pos + 1] == '0') && collition(*data, &data->img, pos + 1, 'V'))
			data->map[pos] = '0';
		else if ((data->map[pos - 1] == 'E' || data->map[pos + lar] == '0') && collition(*data, &data->img, pos + lar, 'V'))
			data->map[pos] = '0';
		else if ((data->map[pos - 1] == 'E' || data->map[pos - lar] == '0') && collition(*data, &data->img, pos - lar, 'V'))
			data->map[pos] = '0';
		else if ((data->map[pos - 1] == 'E' || data->map[pos - 1] == '0') && collition(*data, &data->img, pos - 1, 'V'))
			data->map[pos] = '0';
		enemies--;
	}
	strchng(data->map, 'V', 'W');

}

void	strchng(char *str, int a, int b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		i++;
	}
}
