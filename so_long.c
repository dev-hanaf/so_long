/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:36:49 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 04:06:33 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//  i = y
//  j = x


int map_carre(char *str, t_dimo *data)
{
    ft_split_so_long(str, data, '\n');
    data->c = 0;
    data->p = 0;
    data->e = 0;
    valid_lenght(data);
    check_map(data);
    flood_fill(data, data->x, data->y);
    check_valid_flood_fill(str,data);
    return 0;
}

void check_map_name(char **av)
{
    size_t i;
    char *path = av[1];
    i = ft_strlen(path);
    if (path[i - 5] != '/' && i < 5)
    {
        printf("Error, Ivalid path in the map!!\n");
        exit(0);
    }
    if (path[i - 5] == '/' || path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b' || path[i - 4] != '.' ||  path[i - 5] == '.')
    {
        printf("Error, Ivalid path in the map!!\n");
        exit(0);
    }
}


int loop(t_dimo *data)
{
    mlx_clear_window(data->mlx, data->win);
    draw(data);
    return 1;
}
void    close_window(t_dimo *data)
{
    mlx_destroy_window(data->mlx,data->win);
    // free map
    write(1,"the window closed by user \n",28);
    exit(0);
}

int main(int ac, char **av)
{
    t_dimo data;

    if (ac != 2)
    {
        printf("Takes two arguments!!\n");
        return 0;
    }
    check_map_name(av);
    char *str = get_all_map_lines(av);
    map_carre(str, &data);
   


    data.count_moves = 0;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx,data.width * 32,data.height * 32,"so_long");
    draw(&data);

    mlx_hook(data.win, 2, 0, keys, &data);
    mlx_hook(data.win, 17,0, (void *)close_window, &data);
    mlx_loop_hook(data.mlx, loop, &data );
    mlx_loop(data.mlx);
    // mlx_destroy_display(data.mlx);
    // free(data.mlx);
    free(str);
    return 0;
}
