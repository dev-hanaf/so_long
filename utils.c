/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:34:41 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/02 00:50:49 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_w_message(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	system("leaks so_long");
	exit(1);
}

void	height_map(t_dimo *data)
{
	int	i;

	i = 0;
	while (data->map[i++])
		data->height = i;
}

char	**free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

void	free_str2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return ;
}
