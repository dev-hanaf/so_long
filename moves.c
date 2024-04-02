/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:08:46 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/01 23:47:00 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_dimo *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j + 1] == 'E'
				&& data->c == 0)
			{
						data->count_moves++;
		ft_printf("moves = %d\n", data->count_moves);
						free_str(data->map);
		mlx_destroy_window(data->mlx, data->win);
		system("leaks so_long");
				exit(0);
			}
			if (data->map[i][j] == 'P' && data->map[i][j + 1] != 'E'
				&& data->map[i][j + 1] != '1')
			{
				data->map[i][j] = '0';
				data->map[i][j + 1] = 'P';
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_dimo *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i][j - 1] == 'E'
				&& data->c == 0)
			{
										data->count_moves++;
		ft_printf("moves = %d\n", data->count_moves);
						free_str(data->map);
		mlx_destroy_window(data->mlx, data->win);
		system("leaks so_long");
				exit(0);
			}
			if (data->map[i][j] == 'P' && data->map[i][j - 1] != 'E'
				&& data->map[i][j - 1] != '1')
			{
				data->map[i][j] = '0';
				data->map[i][j - 1] = 'P';
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_dimo *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i - 1][j] == 'E'
				&& data->c == 0)
			{
										data->count_moves++;
		ft_printf("moves = %d\n", data->count_moves);
				free_str(data->map);
				mlx_destroy_window(data->mlx, data->win);
				system("leaks so_long");
				exit(0);
			}
			if (data->map[i][j] == 'P' && data->map[i - 1][j] != 'E'
				&& data->map[i - 1][j] != '1')
			{
				data->map[i][j] = '0';
				data->map[i - 1][j] = 'P';
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_dimo *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && data->map[i + 1][j] == 'E'
				&& data->c == 0)
			{
										data->count_moves++;
		ft_printf("moves = %d\n", data->count_moves);
						free_str(data->map);
				mlx_destroy_window(data->mlx, data->win);
				system("leaks so_long");
				exit(0);
			}
			if (data->map[i][j] == 'P' && data->map[i + 1][j] != 'E'
				&& data->map[i + 1][j] != '1')
			{
				data->map[i][j] = '0';
				data->map[i + 1][j] = 'P';
				data->count_moves++;
				ft_printf("moves = %d\n", data->count_moves);
				return ;
			}
			j++;
		}
		i++;
	}
}
