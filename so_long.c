/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:36:49 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/24 21:39:38 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *get_all_map_lines(char **av)
{
    char *path = av[1];
    int fd = open(path ,O_RDONLY);
    char *lines = NULL;
    if (fd == - 1)
    {
        printf("Error, fd == -1");
        exit(0);
    }
    char *str = get_next_line(fd);
    while ((str != NULL))
    {
        if (str[0] == '\n')
        {
            printf("Error, Invalid map!!");
            exit(0);
        }
        lines = ft_strjoin(lines, str);
        str = get_next_line(fd);
    }
    return lines;
}

void valid_lenght(t_dimo *data)
{
    size_t lenght = ft_strlen(*(data->map));
    int i;

    i = 0;
    while (data->map[i])
    {
        if (ft_strlen(data->map[i]) != lenght)
        {
            printf("Error, The map must be rectangular!!\n");
            exit(0);
        }
        i++;
    }
}

void only_pce01(t_dimo *data, int i, int j)
{
    int isok;

    isok = 0;
    if (data->map[i][j] == '1' || data->map[i][j] == '0' || data->map[i][j] == 'C' || data->map[i][j] == 'P' || data->map[i][j] == 'E')
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
    {
        printf("Error, Impostor character!!\n");
        exit(1);
    }
}

void height_map(t_dimo *data)
{
    int i;

    i = 0;
    while(data->map[i])
        i++;
    data->height = i;
}

void    check_map(t_dimo *data)
{
    int i;
    int len;
    int j;
    
    height_map(data);
    data->width = (int)ft_strlen(*data->map);
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[0][j] != '1' || data->map[i][0] != '1' || data->map[i][data->width - 1] != '1' || data->map[data->height - 1][j] != '1')
            {
                printf("The map must be closed/surrounded by walls!!\n");
                exit(0);
            }
            only_pce01(data, i, j);
            j++;
        }
        i++;
    }
    if (data->p != 1 || data->c < 1 || data->e != 1)
    {
        printf("Error, PCE Problem!!\n");
        exit(1);
    }
}


int map_carre(char *str, t_dimo *data)
{
    ft_split_so_long(str, data, '\n');
    int i = 0;
    valid_lenght(data);
    check_map(data);
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

void count_collectibles(t_dimo *data)
{
    int i = 0;

    data->c = 0;
    int j;
    while (data->map[i])
    {
        j  = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'C')
                data->c++;
        j++;
        }
        i++;
    }
}

int keys(int keycode, t_dimo *data)
    {
        count_collectibles(data);
        if (keycode == ESC)
        {
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
    return 1;
}



void draw(t_dimo *data)
{
        void *player;
    void *wall;
    void *empty;
    void *door;
    void *colicte;
        wall = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm", &data->width, &data->height);
    player = mlx_xpm_file_to_image(data->mlx,"./images/pac_open_right.xpm",&data->width,&data->height);
    door = mlx_xpm_file_to_image(data->mlx,"./images/portal.xpm",&data->width,&data->height);
    colicte = mlx_xpm_file_to_image(data->mlx,"./images/pacdot_food.xpm",&data->width,&data->height);
    // empty = mlx_xpm_file_to_image(data->mlx,"./sprites/Pac-Man/pac_semi_right.xpm",&data->width,&data->height);
    
    int i = 0;
    int j= 0;

    while(data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx,data->win,wall,j*32,i*32);
            if(data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx,data->win,player,j*32,i*32);
            // if(data->map[i][j] == '0')
            //     mlx_put_image_to_window(data->mlx,data->win,empty,j*32,i*32);
            if(data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx,data->win,colicte,j*32,i*32);
            if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx,data->win,door,j*32,i*32);

            j++;
        }
        i++;
    }

}

int loop(t_dimo *data)
{
    mlx_clear_window(data->mlx, data->win);
    draw(data);
    return 1;
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

    //////////// create duplacte map string 
    // int index = 0;
    // data->map_dup = (char **)malloc(sizeof(char *) * (data->height + 1));
    // while (index < data->height)
    // {
    //     data->map_dup[index] = data->map[index];
    //     index++;
    // }
    // data->map_dup[index] = 0;
    // while (*data->map_dup)
    // { 
    //     printf(YELLOW"%s\n"NC,*data->map_dup);
    //     data->map_dup++;
    // }
    ///////////////////////


    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx,data.width * 32,data.height * 32,"so_long");
    draw(&data);

    mlx_hook(data.win, 2, 0, keys, &data);
    mlx_loop_hook(data.mlx, loop, &data );
    mlx_loop(data.mlx);
    // mlx_destroy_display(data.mlx);
    // free(data.mlx);
    free(str);
    return 0;
}

///lines => 11111111111111\n0010000001C110\n000111111111P001\n1E0000011111111111111;
//**s => ["11111111111111","0010000001C110","000111111111P001","E0000011111111111111"];

//s[0] = "1111111111111111111"
//s[1] = "10p1000000000000001"
//s[1] = "1                 1"
//s[-1] = "11111111111111111"