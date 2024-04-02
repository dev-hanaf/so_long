/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:58 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	complete_handle_width_is_zero(int num, int *count, t_val *flag)
{
	ft_print_plus_minus(num, count, flag);
	if (flag->space && num >= 0 && flag->width)
		flag->width--;
	if (flag->space && num >= 0)
		*count += ft_putchar(' ');
	if (num == -2147483648)
	{
		*count += ft_putchar('-');
		flag->width--;
	}
	*count += ft_zero(num, flag->width);
}

void	handle_width(int num, int is_zero, t_val *flag, int *count)
{
	if (flag->minus)
	{
		if (!flag->plus)
			ft_print_space(num, count, flag);
		ft_print_plus_minus(num, count, flag);
		*count += ft_minus(num, flag->width);
	}
	else if (is_zero)
	{
		complete_handle_width_is_zero(num, count, flag);
	}
	else
	{
		if (flag->plus && num >= 0)
			flag->width--;
		ft_print_space(num, count, flag);
		*count += add_spaces(num, flag->width);
		ft_print_plus_minus(num, count, flag);
		*count += ft_putnbr(num);
	}
}

void	handle_width_precision(int num, t_val *flag, int *count)
{
	if (flag->minus)
	{
		flag->after_width = ft_get_precision(flag->prs);
		if (flag->space && num >= 0 && flag->width)
			flag->width--;
		if (flag->space && num >= 0)
			*count += ft_putchar(' ');
		*count += ft_precision_of_minus(num, flag);
	}
	else
	{
		flag->after_width = ft_get_precision(flag->prs);
		if (flag->space && num >= 0 && flag->width)
			flag->width--;
		if (flag->space && num >= 0)
			*count += ft_putchar(' ');
		*count += ft_precision(num, flag);
	}
}

void	first_condition_part(int num, int is_zero, t_val *flag, int *count)
{
	if (count_val_flags(flag) == 0)
		*count += ft_putnbr(num);
	else if (flag->width && !flag->precision)
		handle_width(num, is_zero, flag, count);
	else if (flag->precision)
		handle_width_precision(num, flag, count);
	else
	{
		if (!flag->plus)
			ft_print_space(num, count, flag);
		ft_print_plus_minus(num, count, flag);
		*count += ft_putnbr(num);
	}
}

int	rond_point(t_val *flag, const char *str, int num)
{
	int	count;
	int	is_zero;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
