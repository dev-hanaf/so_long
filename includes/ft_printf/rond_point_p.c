/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:38 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width_p(unsigned long long num, int is_zero, t_val *flag,
		int *count)
{
	if (flag->minus)
	{
		if (!flag->plus)
			ft_print_space_p(count, flag);
		ft_print_plus_minus_p(count, flag);
		*count += ft_putstr("0x");
		*count += ft_minus_p(num, flag->width);
	}
	else if (is_zero)
	{
		if (!flag->plus)
			ft_print_space_p(count, flag);
		ft_print_plus_minus_p(count, flag);
		*count += ft_zero_p(num, flag->width);
	}
	else
	{
		if (flag->plus)
			flag->width--;
		*count += add_spaces_p(num, flag->width);
		ft_print_plus_minus_p(count, flag);
		ft_print_space_p(count, flag);
		*count += ft_putstr("0x");
		*count += ft_putaddresse(num);
	}
}

void	handle_width_precision_p(unsigned long long num, t_val *flag,
		int *count)
{
	if (flag->minus)
	{
		ft_print_space_p(count, flag);
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus_p(num, flag);
	}
	else
	{
		flag->after_width = ft_get_precision(flag->prs);
		ft_print_space_p(count, flag);
		*count += ft_precision_p(num, flag);
	}
}

void	first_condition_part_p(unsigned long long num, int is_zero, t_val *flag,
		int *count)
{
	if (count_val_flags(flag) == 0)
	{
		*count += ft_putstr("0x");
		*count += ft_putaddresse(num);
	}
	else if (flag->width && !flag->precision)
		handle_width_p(num, is_zero, flag, count);
	else if (flag->precision)
		handle_width_precision_p(num, flag, count);
	else
	{
		if (!flag->plus)
			ft_print_space_p(count, flag);
		ft_print_plus_minus_p(count, flag);
		*count += ft_putstr("0x");
		*count += ft_putaddresse(num);
	}
}

int	rond_point_p(t_val *flag, const char *str, unsigned long long num)
{
	int	count;
	int	is_zero;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_p(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
