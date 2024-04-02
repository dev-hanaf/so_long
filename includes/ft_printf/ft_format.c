/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:44:47 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:54:02 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter_number_p(unsigned long long num)
{
	int	i;

	i = 0;
	if (!num)
		return (3);
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int	check_some_flags(char f)
{
	if (f == 'p' || f == 'c' || f == 'c' || f == '%')
		return (1);
	return (0);
}

void	complete_ft_format2(va_list ap, t_val *flag, t_format_args *args,
		int *mode)
{
	if (args->f == 'p')
	{
		flag->end_index = args->index;
		*(args->count) += rond_point_p(flag, args->str, va_arg(ap,
					unsigned long long));
		*mode = 1;
		*flag = ft_bonus(args->f, *mode);
	}
	else if (args->f == 'c')
	{
		flag->end_index = args->index;
		*(args->count) += rond_point_c(flag, args->str, va_arg(ap, int));
		*mode = 1;
		*flag = ft_bonus(args->f, *mode);
	}
	else if (args->f == '%')
	{
		flag->end_index = args->index;
		*(args->count) += rond_point_precentage(flag, args->str, '%');
		*mode = 1;
		*flag = ft_bonus(args->f, *mode);
	}
}

void	complete_ft_format(va_list ap, t_val *flag, t_format_args *args,
		int *mode)
{
	if (args->f == 's')
	{
		flag->end_index = args->index;
		*(args->count) += rond_point_s(flag, args->str, va_arg(ap, char *));
		*mode = 1;
		*flag = ft_bonus(args->f, *mode);
	}
	else if (args->f == 'x')
	{
		flag->end_index = args->index;
		*(args->count) += rond_point_x(flag, args->str, va_arg(ap,
					unsigned int));
		*mode = 1;
		*flag = ft_bonus(args->f, *mode);
	}
	else if (args->f == 'X')
	{
		flag->end_index = args->index;
		*(args->count) += rond_point_xx(flag, args->str, va_arg(ap,
					unsigned int));
		*mode = 1;
		*flag = ft_bonus(args->f, *mode);
	}
	else if (check_some_flags(args->f))
		complete_ft_format2(ap, flag, args, mode);
}

void	ft_format(va_list ap, char f, t_format_args *args)
{
	static t_val	flag;
	static int		mode;

	args->f = f;
	if (ft_mandatory_flags(f) == 0)
		mode = 0;
	flag = ft_bonus(f, mode);
	if (f == 'd' || f == 'i')
	{
		flag.end_index = args->index;
		*(args->count) += rond_point(&flag, args->str, va_arg(ap, int));
		mode = 1;
		flag = ft_bonus(f, mode);
	}
	else if (f == 'u')
	{
		flag.end_index = args->index;
		*(args->count) += rond_point_u(&flag, args->str, va_arg(ap,
					unsigned int));
		mode = 1;
		flag = ft_bonus(f, mode);
	}
	else
		complete_ft_format(ap, &flag, args, &mode);
}
