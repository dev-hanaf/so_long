/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:58 by ajordan-          #+#    #+#             */
/*   Updated: 2024/03/16 11:19:11 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_next_line(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_next_line(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_next_line(char *remainder, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!remainder)
	{
		remainder = (char *)malloc(1 * sizeof(char));
		remainder[0] = '\0';
	}
	if (!remainder || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_next_line(remainder)
					+ ft_strlen_next_line(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (remainder)
		while (remainder[++i] != '\0')
			str[i] = remainder[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_next_line(remainder) + ft_strlen_next_line(buff)] = '\0';
	free(remainder);
	return (str);
}

char	*ft_get_line(char *remainder)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_next_line(remainder) - i
				+ 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}
