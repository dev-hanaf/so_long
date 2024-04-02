/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/01/05 09:54:20 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_of_minus_u(t_val *flag, unsigned int num, int *count)
{
	int	len;
	int	width;

	len = counter_number_u(num);
	width = 0;
	if (flag->width > len && flag->after_width == 0 && num == 0)
		len = 0;
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

int	ft_precision_of_minus_u(unsigned int num, t_val *flag)
{
	int				len;
	int				count;
	int				precision;
	unsigned int	tmp;

	precision = flag->after_width;
	tmp = num;
	count = 0;
	len = counter_number_u(tmp);
	if (flag->plus)
		count += ft_putchar('+');
	if (num == 0 && precision == 0)
		count += 0;
	else
	{
		if (precision > len)
		{
			while (precision-- - len > 0)
				count += ft_putchar('0');
		}
		count += ft_putnbr_u(tmp);
	}
	ft_completion_of_minus_u(flag, num, &count);
	return (count);
}

void	ft_completion_of_regular_u(int len, t_val *flag, unsigned int num,
		int *count)
{
	int	precision;

	if (flag->plus)
		*count += ft_putchar('+');
	if (num == 0 && flag->after_width == 0)
		return ;
	else
	{
		if (flag->after_width > len)
		{
			precision = flag->after_width - len;
			while (precision-- > 0)
				*count += ft_putchar('0');
		}
		*count += ft_putnbr_u(num);
	}
}

int	ft_precision_u(unsigned int num, t_val *flag)
{
	int	len;
	int	count;
	int	width;

	len = counter_number_u(num);
	count = 0;
	width = 0;
	if (flag->width > len && flag->after_width == 0 && num == 0)
		len = 0;
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
	ft_completion_of_regular_u(len, flag, num, &count);
	return (count);
}
