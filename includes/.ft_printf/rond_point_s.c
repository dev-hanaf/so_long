/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond_point_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:15 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/26 02:30:18 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width_s(t_val *flag, char *arg, int *count)
{
	if (flag->minus)
	{
		if (flag->after_width >= 6 && arg == NULL)
			*count += ft_putstr("(null)");
		else
			*count += ft_putstr(arg);
		*count += add_spaces_s(arg, flag->width);
	}
	else
	{
		*count += add_spaces_s(arg, flag->width);
		if (flag->after_width >= 6 && arg == NULL)
			*count += ft_putstr("(null)");
		else
			*count += ft_putstr(arg);
	}
}

void	handle_only_precision_s(char *arg, t_val *flag, int *count)
{
	flag->after_width = ft_get_precision(flag->prs);
	if (flag->after_width >= 6 && arg == NULL)
		*count += ft_putstr("(null)");
	if (flag->after_width <= (int)ft_strlen_printf(arg))
	{
		while (flag->after_width > 0)
		{
			*count += ft_putchar(*arg);
			arg++;
			flag->after_width--;
		}
	}
	else
	{
		*count += ft_putstr(arg);
	}
}

void	first_condition_part_s(char *arg, t_val *flag, int *count)
{
	if (count_val_flags(flag) == 0)
		*count += ft_putstr(arg);
	else if (flag->width && !flag->precision)
		handle_width_s(flag, arg, count);
	else if (flag->precision)
	{
		if (flag->minus)
		{
			flag->after_width = ft_get_precision(flag->prs);
			*count += ft_precision_of_minus_s(arg, flag->after_width,
					flag->width);
		}
		else
		{
			flag->after_width = ft_get_precision(flag->prs);
			*count += ft_precision_s(arg, flag->after_width, flag->width);
		}
	}
	else if (!flag->width && flag->precision)
		handle_only_precision_s(arg, flag, count);
	else
	{
		*count += ft_putstr(arg);
	}
}

int	rond_point_s(t_val *flag, const char *str, char *arg)
{
	int	count;

	flag->start_index = flag->end_index - count_val_flags(flag);
	flag->prs = ft_parser(str, flag->start_index, flag->end_index);
	count = 0;
	flag->width = ft_width(flag->prs);
	first_condition_part_s(arg, flag, &count);
	free(flag->prs);
	return (count);
}
