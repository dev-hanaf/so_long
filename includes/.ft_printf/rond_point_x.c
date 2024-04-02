/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:53 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width_x(unsigned int num, int is_zero, t_val *flag, int *count)
{
	if (flag->minus)
	{
		if (flag->hash && num != 0)
			*count += ft_putstr("0x");
		*count += ft_minus_x(num, flag->width, flag);
	}
	else if (is_zero)
	{
		if (flag->hash && num != 0)
			*count += ft_putstr("0x");
		*count += ft_zero_x(num, flag->width, flag);
	}
	else
	{
		*count += add_spaces_x(num, flag->width, flag);
		if (flag->hash && num != 0)
			*count += ft_putstr("0x");
		*count += ft_puthexa(num, 'x');
	}
}

void	handle_width_precision_x(unsigned int num, t_val *flag, int *count)
{
	if (flag->minus)
	{
		flag->after_width = ft_get_precision(flag->prs);
		if (flag->hash && num != 0 && !flag->after_width)
			flag->width += 2;
		if (flag->hash && num != 0 && flag->width > flag->after_width)
			flag->width -= 2;
		*count += ft_precision_of_minus_x(num, flag);
	}
	else
	{
		flag->after_width = ft_get_precision(flag->prs);
		if (flag->hash && num != 0 && !flag->after_width)
			flag->width += 2;
		if (flag->hash && num != 0 && flag->width > flag->after_width)
			flag->width -= 2;
		*count += ft_precision_x(num, flag);
	}
}

void	first_condition_part_x(unsigned int num, int is_zero, t_val *flag,
		int *count)
{
	if (count_val_flags(flag) == 0)
		*count += ft_puthexa(num, 'x');
	else if (flag->width && !flag->precision)
		handle_width_x(num, is_zero, flag, count);
	else if (flag->precision)
		handle_width_precision_x(num, flag, count);
	else
	{
		if (num != 0 && flag->hash)
			*count += ft_putstr("0x");
		*count += ft_puthexa(num, 'x');
	}
}

int	rond_point_x(t_val *flag, const char *str, unsigned int num)
{
	int	count;
	int	is_zero;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_x(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
