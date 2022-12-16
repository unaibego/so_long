/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:50:37 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/15 13:46:02 by ubegona          ###   ########.fr       */
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
	int		lar;

	pos = 0;
	lar = 0;
	test_map = ft_strdup(data.map);
	while (data.map[pos] != 'E')
		pos++;
	while (data.map[lar - 1] != '\n')
		lar++;
	test_map = next_step(test_map, pos, lar);
	pos = 0;
	while (test_map[pos])
	{
		if (test_map[pos] == 'P' || test_map[pos] == 'E'
			|| test_map[pos] == 'C')
		{
			write(1, "error\n", 6),
			exit (0);
		}
		pos++;
	}
}
