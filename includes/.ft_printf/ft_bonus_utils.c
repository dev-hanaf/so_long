/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:14:50 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:53:46 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_spaces(int num, int width)
{
	int	count;
	int	len;

	count = 0;
	len = counter_number(num);
	if (num <= 0)
		width--;
	while (width-- - len > 0)
		count += ft_putchar(' ');
	return (count);
}

void	ft_print_plus(int num, int *count, t_val *flag)
{
	if (num >= 0 && flag->plus)
	{
		flag->width--;
		*count += add_spaces(num, flag->width);
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_plus_minus(int num, int *count, t_val *flag)
{
	if (num >= 0 && flag->plus)
	{
		*count += ft_putchar('+');
		flag->width--;
	}
}

void	ft_print_space(int num, int *count, t_val *flag)
{
	if (num >= 0 && flag->space && !flag->plus)
	{
		*count += ft_putchar(' ');
		flag->width--;
	}
}

int	check_zero_is_flag(char *prs)
{
	int	i;

	i = 0;
	while (prs[i])
	{
		if (prs[i] == '0' && i > 0)
		{
			if (!ft_isdigit(prs[i - 1]))
				return (1);
		}
		i++;
	}
	return (0);
}
