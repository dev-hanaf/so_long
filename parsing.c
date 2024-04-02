/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:05:55 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/01 23:58:02 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_str2(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return ;
}

void get_all_map_lines(char **av, t_dimo *data)
{
	char	*path;
	int		fd;
	char	*lines;
	char	*str;
	char	*tmp;
	
	size_t	lenght;
	path = av[1];
	fd = open(path, O_RDONLY);
	lines = NULL;
	if (fd == -1)
		ft_exit_w_message("Error, fd == -1");
	str = get_next_line(fd);
	lenght = ft_strlen_without_nl(str);
	if (!lenght)
		ft_exit_w_message("ERROR, empty map");
	int i = 0;
	while ((str != NULL))
	{
		i++;
		if (str[lenght - 1] == '\n')
			tmp = ft_substr(str, 0, lenght -1);
		else
			tmp = ft_substr(str, 0, lenght);
		printf(GREEN"%zu\n"NC,ft_strlen_without_nl(str));
		lines = ft_strjoin(lines, tmp);
		free(str);
		free(tmp);
		str = get_next_line(fd);
		if (lenght != ft_strlen_without_nl(str) && str)
			ft_exit_w_message("Error, The map must be rectangular!!");
	}
	printf(YELLOW"|%s|\n"NC,lines);
	printf("i = > %d\n", i);
	data->map = (char **)malloc(sizeof(char **) * i + 1);
	if (!data->map)
		return ;
	int j = 0;
	int start = 0;
	int end = (int)lenght ;
	while (j < i)
	{
		data->map[j] = ft_substr(lines, start , end);
		if (!data->map[j])
			return (free_str2(data->map));
		start += lenght ;
		j++;
	}
	data->map[j] = 0;
	free(str);
	i = 0;
	while(data->map[i])
	{
		printf("%s\n",data->map[i++]);
	}
	data->height = i;
	data->width = lenght;
	free(lines);
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
	int x = 0;
	while(str[x])
		printf(RED"%s\n"NC,str[x++]);
	// height_map(data);
	// data->width = (int)ft_strlen(*data->map);
	printf(YELLOW"%d\n"NC,data->width);
	printf(YELLOW"%d\n"NC,data->height);

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			printf(CYAN"%c\n"NC,str[0][j]);
			printf(CYAN"%c\n"NC,str[i][0]);
			printf(CYAN"%c\n"NC,str[i][data->width - 1]);
			printf(CYAN"%c\n"NC,str[data->height -1][j]);
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
