/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:02:19 by ubegona           #+#    #+#             */
/*   Updated: 2022/12/16 12:16:37 by ubegona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char s2, char const *s3)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	i = 0;
	j = 0;
	p = malloc(ft_strlen(s1) + ft_strlen(s3) + 2);
	if (p == 0)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i++] = s2;
	j = 0;
	while (s3[j])
		p[i++] = s3[j++];

	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen(s1);
	p = malloc(j + 1);
	if (p == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;

	len = ft_strlen(s);
	write(fd, s, len);
}
