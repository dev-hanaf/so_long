/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:50 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width_u(unsigned int num, int is_zero, t_val *flag, int *count)
{
	if (flag->minus)
	{
		*count += ft_minus_u(num, flag->width);
	}
	else if (is_zero)
	{
		*count += ft_zero_u(num, flag->width);
	}
	else
	{
		if (flag->plus)
			flag->width--;
		*count += add_spaces_u(num, flag->width);
		*count += ft_putnbr_u(num);
	}
}

void	handle_width_precision_u(unsigned int num, t_val *flag, int *count)
{
	if (flag->minus)
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_of_minus_u(num, flag);
	}
	else
	{
		flag->after_width = ft_get_precision(flag->prs);
		*count += ft_precision_u(num, flag);
	}
}

void	first_condition_part_u(unsigned int num, int is_zero, t_val *flag,
		int *count)
{
	if (count_val_flags(flag) == 0)
		*count += ft_putnbr_u(num);
	else if (flag->width && !flag->precision)
		handle_width_u(num, is_zero, flag, count);
	else if (flag->precision)
		handle_width_precision_u(num, flag, count);
	else
	{
		*count += ft_putnbr_u(num);
	}
}

int	rond_point_u(t_val *flag, const char *str, unsigned int num)
{
	int	count;
	int	is_zero;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	is_zero = check_zero_is_flag(flag->prs);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_u(num, is_zero, flag, &count);
	free(flag->prs);
	return (count);
}
