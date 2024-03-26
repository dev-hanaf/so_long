/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:08:46 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 02:10:24 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_right(t_dimo *data)
{
    int i = 0;
    int j;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'P' && data->map[i][j + 1] == 'E' && data->c == 0)
                exit(1);
            if (data->map[i][j] == 'P' && data->map[i][j + 1] != 'E' && data->map[i][j + 1] != '1')
            {    
                data->map[i][j] = '0';
                data->map[i][j + 1] = 'P';
                data->count_moves++;
                ft_printf("moves = %d\n",data->count_moves);
                return ;
            }
            j++;
        }
        i++;
    }
}
void move_left(t_dimo *data)
{
    int i = 0;
    int j;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'P' && data->map[i][j - 1] == 'E' && data->c == 0)
                exit(1);
            if (data->map[i][j] == 'P' && data->map[i][j - 1] != 'E' && data->map[i][j - 1] != '1')
            {    
                data->map[i][j] = '0';
                data->map[i][j - 1] = 'P';
                data->count_moves++;
                ft_printf("moves = %d\n",data->count_moves);
                return ;
            }
            j++;
        }
        i++;
    }
}
void move_up(t_dimo *data)
{
    int i = 0;
    int j;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'P' && data->map[i - 1][j] == 'E' && data->c == 0)
                exit(1);
            if (data->map[i][j] == 'P' && data->map[i - 1][j] != 'E' && data->map[i - 1][j] != '1')
            {    
                data->map[i][j] = '0';
                data->map[i - 1][j] = 'P';
                data->count_moves++;
                ft_printf("moves = %d\n",data->count_moves);
                return ;
            }
            j++;
        }
        i++;
    }
}
void move_down(t_dimo *data)
{
    int i = 0;
    int j;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == 'P' && data->map[i + 1][j] == 'E' && data->c == 0)
                exit(1);
            if (data->map[i][j] == 'P' && data->map[i + 1][j] != 'E' && data->map[i + 1][j] != '1')
            {    
                data->map[i][j] = '0';
                data->map[i + 1][j] = 'P';
                data->count_moves++;
                ft_printf("moves = %d\n",data->count_moves);
                return ;
            }
            j++;
        }
        i++;
    }
}
