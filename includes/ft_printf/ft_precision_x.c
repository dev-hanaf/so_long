/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/01/05 09:54:22 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_of_minus_x(t_val *flag, unsigned int num, int *count)
{
	int	len;
	int	width;

	len = counter_number_x(num, flag);
	if (flag->hash && num != 0 && flag->after_width)
		len -= 2;
	width = 0;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len;
	else if (flag->width > len)
		width = flag->width - len;
	if (num == 0 && flag->after_width == 0 && flag->width > len - 1)
		width = flag->width;
	if (flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			*count += ft_putchar(' ');
	}
}

int	ft_precision_of_minus_x(unsigned int num, t_val *flag)
{
	int				len;
	int				count;
	int				precision;
	unsigned int	tmp;

	precision = flag->after_width;
	tmp = num;
	count = 0;
	len = counter_number_x(tmp, flag);
	if (flag->hash && num != 0)
		len -= 2;
	if (flag->hash && num != 0)
		count += ft_putstr("0x");
	if (precision > len)
	{
		while (precision-- - len > 0)
			count += ft_putchar('0');
	}
	if (num != 0 || flag->after_width != 0)
		count += ft_puthexa(tmp, 'x');
	ft_completion_of_minus_x(flag, num, &count);
	return (count);
}

void	ft_completion_of_regular_x(int len, t_val *flag, unsigned int num,
		int *count)
{
	int	precision;

	if (flag->hash && num != 0)
		*count += ft_putstr("0x");
	if (flag->after_width > len)
	{
		precision = flag->after_width - len;
		while (precision-- > 0)
			*count += ft_putchar('0');
	}
	if (num != 0 || flag->after_width != 0)
		*count += ft_puthexa(num, 'x');
}

int	ft_precision_x(unsigned int num, t_val *flag)
{
	int	len;
	int	count;
	int	width;

	len = counter_number_x(num, flag);
	if (flag->hash && num != 0 && flag->after_width)
		len -= 2;
	count = 0;
	width = 0;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len;
	else if (flag->width > len)
		width = flag->width - len;
	if (num == 0 && flag->after_width == 0 && flag->width > len - 1)
		width = flag->width;
	if (flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	ft_completion_of_regular_x(len, flag, num, &count);
	return (count);
}
