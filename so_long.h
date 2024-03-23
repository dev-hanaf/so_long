/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:40:30 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/22 03:38:45 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

/////////////////////////
#include "./includes/get_next_line/get_next_line.h"
// #include "./includes/ft_printf/ft_printf.h"

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
}t_dimo;

char  **ft_split_so_long(char *str, t_dimo *dimo ,char sep);



#endif