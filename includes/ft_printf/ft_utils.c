/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:02:40 by new               #+#    #+#             */
/*   Updated: 2024/03/26 02:30:12 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter_number(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
		return (10);
	if (num < 0)
	{
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	counter_number_u(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	counter_number_x(unsigned int num, t_val *flag)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num != 0 && flag->hash)
		i += 2;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

size_t	ft_strlen_printf(const char *str)
{
	size_t	i;

	if (!str)
		return (6);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
