/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/01/05 09:54:15 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_of_minus_p(t_val *flag, unsigned long long num,
		int *count)
{
	int	len;
	int	width;

	len = counter_number_p(num);
	width = 0;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len - 2;
	else if (flag->width > len)
		width = flag->width - len - 2;
	if (flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			*count += ft_putchar(' ');
	}
}

int	ft_precision_of_minus_p(unsigned long long num, t_val *flag)
{
	int					len;
	int					count;
	int					precision;
	unsigned long long	tmp;

	precision = flag->after_width;
	tmp = num;
	count = 0;
	len = counter_number_p(tmp);
	if (flag->plus)
		count += ft_putchar('+');
	count += ft_putstr("0x");
	if (precision > len)
	{
		while (precision-- - len > 0)
			count += ft_putchar('0');
	}
	if (tmp != 0)
		count += ft_putaddresse(tmp);
	ft_completion_of_minus_p(flag, num, &count);
	return (count);
}

void	ft_completion_of_regular_p(int len, t_val *flag, unsigned long long num,
		int *count)
{
	int	precision;

	if (flag->plus)
		*count += ft_putchar('+');
	*count += ft_putstr("0x");
	if (flag->after_width > len)
	{
		precision = flag->after_width - len;
		while (precision-- > 0)
			*count += ft_putchar('0');
	}
	if (num != 0)
	{
		*count += ft_putaddresse(num);
	}
}

int	ft_precision_p(unsigned long long num, t_val *flag)
{
	int	len;
	int	count;
	int	width;

	len = counter_number_p(num);
	count = 0;
	width = 0;
	if (flag->after_width > len)
		width = flag->width - (flag->after_width - len) - len - 2;
	else if (flag->width > len)
		width = flag->width - len - 2;
	if (flag->plus)
		width--;
	if (width > 0)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	ft_completion_of_regular_p(len, flag, num, &count);
	return (count);
}
