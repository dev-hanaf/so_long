/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:08:46 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/03 20:14:59 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dispaly_moves_exit(t_dimo *data)
{
	data->count_moves++;
	ft_printf("moves = %d\n", data->count_moves);
	free_str(data->map);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	move_right(t_dimo *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j + 1] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->map[i][j] == 'P' && data->map[i][j + 1] != 'E'
				&& data->map[i][j + 1] != '1')
			{
				data->map[i][j] = '0';
				data->map[i][j + 1] = 'P';
				draw(data);
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
	}
}

void	move_left(t_dimo *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j - 1] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->map[i][j] == 'P' && data->map[i][j - 1] != 'E'
				&& data->map[i][j - 1] != '1')
			{
				data->map[i][j] = '0';
				data->map[i][j - 1] = 'P';
				draw(data);
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
	}
}

void	move_up(t_dimo *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i - 1][j] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->map[i][j] == 'P' && data->map[i - 1][j] != 'E'
				&& data->map[i - 1][j] != '1')
			{
				data->map[i][j] = '0';
				data->map[i - 1][j] = 'P';
				draw(data);
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
	}
}

void	move_down(t_dimo *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i + 1][j] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->map[i][j] == 'P' && data->map[i + 1][j] != 'E'
				&& data->map[i + 1][j] != '1')
			{
				data->map[i][j] = '0';
				data->map[i + 1][j] = 'P';
				draw(data);
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
	}
}
