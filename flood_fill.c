/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:53:56 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 04:14:31 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_dimo *data, int j, int i)
{
	if (data->map[i][j] == 'P' || data->map[i][j] == '0'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'C')
	{
		data->map[i][j] = 'X';
		flood_fill(data, j, i + 1);
		flood_fill(data, j, i + 1);
		flood_fill(data, j - 1, i);
		flood_fill(data, j + 1, i);
	}
}

void	check_valid_flood_fill(char *str, t_dimo *data)
{
	int	i;
	int	j;

	i = 0;
	display_str(data);
	while (data->map[i])
	{
		printf(YELLOW"%s\n"NC,data->map[i++]);
	}
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				ft_exit_w_message("C NOT REACH!!", 2);
			if (data->map[i][j] == 'E')
				ft_exit_w_message("E NOT REACH!!", 2);

			j++;
		}
		i++;
	}
	ft_split_so_long(str, data, '\n');
}
