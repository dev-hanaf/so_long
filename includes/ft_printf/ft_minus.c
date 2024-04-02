/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:14:00 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 02:29:52 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minus(int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number(num);
	if (num <= 0)
		width--;
	count += ft_putnbr(num);
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	ft_minus_u(unsigned int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_u(num);
	count += ft_putnbr_u(num);
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	ft_minus_s(char *arg, int width)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen_printf(arg);
	count += ft_putstr(arg);
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	ft_minus_x(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_x(num, flag);
	count += ft_puthexa(num, 'x');
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	ft_minus_xx(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_x(num, flag);
	count += ft_puthexa(num, 'X');
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}
