/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:32:04 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:20 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zero(int num, int width)
{
	int	count;
	int	len;

	len = counter_number(num);
	count = 0;
	if (num < 0 && num != -2147483648)
	{
		count += ft_putchar('-');
		width--;
		num *= -1;
	}
	if (num == 0)
		len += 1;
	while (width-- - len > 0)
		count += ft_putchar('0');
	if (num == -2147483648)
		count += ft_putstr("2147483648");
	else
		count += ft_putnbr(num);
	return (count);
}

int	ft_zero_u(unsigned int num, int width)
{
	int	count;
	int	len;

	len = counter_number_u(num);
	count = 0;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_putnbr_u(num);
	return (count);
}

int	ft_zero_x(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	len = counter_number_x(num, flag);
	count = 0;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_puthexa(num, 'x');
	return (count);
}

int	ft_zero_xx(unsigned int num, int width, t_val *flag)
{
	int	count;
	int	len;

	len = counter_number_x(num, flag);
	count = 0;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_puthexa(num, 'X');
	return (count);
}

int	ft_zero_p(unsigned long long num, int width)
{
	int	count;
	int	len;

	len = counter_number_p(num);
	if (num == 0)
		width--;
	count = 0;
	count += ft_putstr("0x");
	len += 2;
	while (width-- - len > 0)
		count += ft_putchar('0');
	count += ft_putaddresse(num);
	return (count);
}
