/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:36:49 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/01 23:20:57 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	map_carre(char **av, t_dimo *data)
{
	data->c = 0;
	data->p = 0;
	data->e = 0;
	check_map(data);
	flood_fill(data, data->x, data->y);
	check_valid_flood_fill(av , data);
	return (0);
}

void	check_map_name(char **av)
{
	size_t	i;
	char	*path;

	path = av[1];
	i = ft_strlen(path);
	if (path[i - 5] != '/' && i < 5)
		ft_exit_w_message("Error, Ivalid path in the map!!");
	if (path[i - 5] == '/' || path[i - 1] != 'r' || path[i - 2] != 'e')
		ft_exit_w_message("Error, Ivalid path in the map!!");
	if (path[i - 3] != 'b' || path[i - 4] != '.')
		ft_exit_w_message("Error, Ivalid path in the map!!");
}

int	loop(t_dimo *data)
{
	mlx_clear_window(data->mlx, data->win);
	initialize_mlx_vars(data);
	return (1);
}

void	close_window(t_dimo *data)
{
	mlx_destroy_window(data->mlx, data->win);
	write(1, "the window closed by user \n", 28);
	exit(0);
}



int	main(int ac, char **av)
{
	t_dimo	data;
	// char	*str;
	data.height	=	0;
	if (ac != 2)
	{
		ft_printf("%s\n","Takes two arguments!!");
		return (0);
	}
	check_map_name(av);
	get_all_map_lines(av, &data);
	map_carre(av ,&data);
	data.count_moves = 0;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	data.win = mlx_new_window(data.mlx, data.width * 32, data.height * 32,
			"so_long");
	if (data.win == NULL)
		return 0;
	initialize_mlx_vars(&data);
	mlx_hook(data.win, 2, 0, keys, &data);
	mlx_hook(data.win, 17, 0, (void *)close_window, &data);
	mlx_loop_hook(data.mlx, loop, &data);
	mlx_loop(data.mlx);
	// free(str);
	free_str(data.map);
	return (0);
}
