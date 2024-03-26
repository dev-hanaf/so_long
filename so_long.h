/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:40:30 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 04:05:27 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

/////////////////////////
#include "./includes/get_next_line/get_next_line.h"
#include "./includes/ft_printf/ft_printf.h"
#include "./includes/libft/libft.h"

////////////////////////

# define NC "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>


#define ESC     53
#define W       13
#define A	    0
#define S	    1
#define D	    2

typedef struct s_dimo
{
    void  *mlx;
    void *win;
    int height;
    int width;
    char **map;
    int x;
    int y;
    int p;
    int e;
    int c;
    int count_moves;
    void *player;
    void *wall;
    void *door;
    void *coll;
}t_dimo;

char  **ft_split_so_long(char *str, t_dimo *dimo ,char sep);
char	*get_all_map_lines(char **av);
void	ft_exit_w_message(char *message ,int fd);
void height_map(t_dimo *data);

void move_right(t_dimo *data);
void move_down(t_dimo *data);
void move_left(t_dimo *data);
void move_up(t_dimo *data);
void	valid_lenght(t_dimo *data);
void	only_pce01(t_dimo *data, int i, int j);
void	check_map(t_dimo *data);
void flood_fill(t_dimo *data, int j, int i);
void check_valid_flood_fill(char *str,t_dimo *data);
void count_collectibles(t_dimo *data);
void draw(t_dimo *data);
int keys(int keycode, t_dimo *data);
void display_str(t_dimo *data);
#endif