/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_precentage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:40 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width_precentage(char c, int is_zero, t_val *flag, int *count)
{
	if (flag->minus)
	{
		*count += ft_putchar(c);
		while (flag->width-- - 1 > 0)
			*count += ft_putchar(' ');
	}
	else if (is_zero)
	{
		while (flag->width-- - 1 > 0)
			*count += ft_putchar('0');
		*count += ft_putchar(c);
	}
	else
	{
		while (flag->width-- - 1 > 0)
			*count += ft_putchar(' ');
		*count += ft_putchar(c);
	}
}

void	first_condition_part_precentage(char c, int is_zero, t_val *flag,
		int *count)
{
	if (count_val_flags(flag) == 0)
		*count += ft_putchar(c);
	else if (flag->width && !flag->precision)
		handle_width_precentage(c, is_zero, flag, count);
	else if (flag->precision)
		handle_width_precentage(c, is_zero, flag, count);
	else
	{
		*count += ft_putchar(c);
	}
}

int	rond_point_precentage(t_val *flag, const char *str, char c)
{
	int	count;
	int	is_zero;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_precentage(c, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
