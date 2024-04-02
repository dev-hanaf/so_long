/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_xx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:19:00 by new               #+#    #+#             */
/*   Updated: 2024/01/05 09:54:27 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_of_minus_xx(t_val *flag, unsigned int num, int *count)
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

int	ft_precision_of_minus_xx(unsigned int num, t_val *flag)
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
		count += ft_putstr("0X");
	if (precision > len)
	{
		while (precision-- - len > 0)
			count += ft_putchar('0');
	}
	if (num != 0 || flag->after_width != 0)
		count += ft_puthexa(tmp, 'X');
	ft_completion_of_minus_xx(flag, num, &count);
	return (count);
}

void	ft_completion_of_regular_xx(int len, t_val *flag, unsigned int num,
		int *count)
{
	int	precision;

	if (flag->hash && num != 0)
		*count += ft_putstr("0X");
	if (flag->after_width > len)
	{
		precision = flag->after_width - len;
		while (precision-- > 0)
			*count += ft_putchar('0');
	}
	if (num != 0 || flag->after_width != 0)
		*count += ft_puthexa(num, 'X');
}

int	ft_precision_xx(unsigned int num, t_val *flag)
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
	ft_completion_of_regular_xx(len, flag, num, &count);
	return (count);
}
