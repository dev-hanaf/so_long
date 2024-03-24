/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:34:41 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/24 12:38:14 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_w_message(char *message ,int fd, int code)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	return (code);
}

