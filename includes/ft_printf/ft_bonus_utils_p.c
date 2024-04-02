/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:50 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:53:30 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_spaces_p(unsigned long long num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_p(num);
	if (num)
		len += 2;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

void	ft_print_plus_p(unsigned long long num, int *count, t_val *flag)
{
	if (flag->plus)
	{
		flag->width--;
		*count += add_spaces_p(num, flag->width);
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_plus_minus_p(int *count, t_val *flag)
{
	if (flag->plus)
	{
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_space_p(int *count, t_val *flag)
{
	if (flag->space && !flag->plus)
	{
		*count += ft_putchar(' ');
		flag->width--;
	}
}

int	ft_minus_p(unsigned long long num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number_p(num);
	count += ft_putaddresse(num);
	if (num)
		len += 2;
	while (width - len > 0)
	{
		count += ft_putchar(' ');
		width--;
	}
	return (count);
}
