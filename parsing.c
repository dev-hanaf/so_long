/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:05:55 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 07:36:57 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_all_map_lines(char **av)
{
	char	*path;
	int		fd;
	char	*lines;
	char	*str;

	path = av[1];
	fd = open(path, O_RDONLY);
	lines = NULL;
	if (fd == -1)
		ft_exit_w_message("Error, fd == -1");
	str = get_next_line(fd);
	while ((str != NULL))
	{
		if (str[0] == '\n')
			ft_exit_w_message("Error, Invalid map!!");
		lines = ft_strjoin(lines, str);
		str = get_next_line(fd);
	}
	return (lines);
}

void	valid_lenght(t_dimo *data)
{
	size_t	lenght;
	int		i;

	lenght = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != lenght)
			ft_exit_w_message("Error, The map must be rectangular!!");
		i++;
	}
}

void	only_pce01(t_dimo *data, int i, int j)
{
	int	isok;

	isok = 0;
	if (data->map[i][j] == '1' || data->map[i][j] == '0'
		|| data->map[i][j] == 'C' || data->map[i][j] == 'P'
		|| data->map[i][j] == 'E')
	{
		isok = 1;
		if (data->map[i][j] == 'P')
		{
			data->x = j;
			data->y = i;
			data->p++;
		}
		if (data->map[i][j] == 'C')
			data->c++;
		if (data->map[i][j] == 'E')
			data->e++;
	}
	if (!isok)
		ft_exit_w_message("Error, Impostor character!!");
}

void	check_map(t_dimo *data)
{
	int		i;
	int		len;
	int		j;
	char	**str;

	str = data->map;
	height_map(data);
	data->width = (int)ft_strlen(*data->map);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[0][j] != '1' || str[i][0] != '1' || str[i][data->width
				- 1] != '1' || str[data->height - 1][j] != '1')
				ft_exit_w_message("The map must be closed/surrounded by walls");
			only_pce01(data, i, j);
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->c < 1 || data->e != 1)
		ft_exit_w_message("Error, PCE Problem!!");
}
