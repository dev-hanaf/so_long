/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:05:55 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/03 20:25:29 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_data_map(t_dimo *data)
{
	int	j;
	int	start;
	int	end;

	data->map = (char **)malloc(sizeof(char **) * data->height + 1);
	if (!data->map)
		return ;
	j = 0;
	start = 0;
	end = data->width;
	while (j < data->height)
	{
		data->map[j] = ft_substr(data->lines, start, end);
		if (!data->map[j])
			return (free_str2(data->map));
		start += data->width;
		j++;
	}
	data->map[j] = 0;
}

char	*substring_str(char *str, t_dimo *data)
{
	char	*tmp;

	if (str[data->width - 1] == '\n')
		tmp = ft_substr(str, 0, data->width - 1);
	else
		tmp = ft_substr(str, 0, data->width);
	return (tmp);
}

void	get_all_map_lines(char **av, t_dimo *data)
{
	int		fd;
	char	*str;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit_w_message("Error, fd == -1");
	str = get_next_line(fd);
	data->width = (int)ft_strlen_without_nl(str);
	if (!data->width)
		ft_exit_w_message("ERROR");
	while ((str != NULL))
	{
		data->height++;
		tmp = substring_str(str, data);
		data->lines = ft_strjoin(data->lines, tmp);
		free(str);
		free(tmp);
		str = get_next_line(fd);
		if (data->width != (int)ft_strlen_without_nl(str) && str)
			ft_exit_w_message("Error, The map must be rectangular!!");
	}
	create_data_map(data);
	free(str);
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
	int		j;
	char	**str;

	str = data->map;
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
