/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 03:01:05 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/03 20:14:53 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_dimo *data)
{
	int	i;
	int	j;

	i = 0;
	data->c = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c++;
			j++;
		}
		i++;
	}
}

void	message_xpm(t_dimo *data)
{
	if (!data->player || !data->wall || !data->door || !data->coll)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		free_str(data->map);
		ft_exit_w_message("Error, Invalid xpm");
	}
}

void	initialize_mlx_vars(t_dimo *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/pac_open_right.xpm",
			&data->width,
			&data->height);
	data->door = mlx_xpm_file_to_image(data->mlx, "./textures/portal.xpm",
			&data->width, &data->height);
	data->coll = mlx_xpm_file_to_image(data->mlx, "./textures/pacdot_food.xpm",
			&data->width, &data->height);
	message_xpm(data);
}

void	draw(t_dimo *data)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j
					* 32, i * 32);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player, j
					* 32, i * 32);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->coll, j
					* 32, i * 32);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->door, j
					* 32, i * 32);
			j++;
		}
	}
}

int	keys(int keycode, t_dimo *data)
{
	count_collectibles(data);
	if (keycode == ESC)
	{
		free_str(data->map);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == W)
		move_up(data);
	if (keycode == A)
		move_left(data);
	if (keycode == S)
		move_down(data);
	if (keycode == D)
		move_right(data);
	return (1);
}
