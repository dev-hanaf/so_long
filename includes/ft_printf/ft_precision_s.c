/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:00:59 by new               #+#    #+#             */
/*   Updated: 2024/03/26 02:30:00 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_completion_of_minus_s(int width, int precision, char *arg,
		int *count)
{
	size_t	len;

	len = ft_strlen_printf(arg);
	if (precision <= (int)len)
		len = (size_t)precision;
	if (width && !precision)
	{
		while (width-- > 0)
			*count += ft_putchar(' ');
	}
	else
	{
		while (width-- - (int)len > 0)
			*count += ft_putchar(' ');
	}
}

int	ft_precision_of_minus_s(char *arg, int precision, int width)
{
	int		count;
	int		tmp;
	char	*tmp_arg;
	char	*nl;
	int		i;

	i = 0;
	nl = "(null)";
	count = 0;
	tmp = precision;
	tmp_arg = arg;
	if (precision >= 6 && arg == NULL)
		count += ft_putstr("(null)");
	else if (arg == NULL)
		while (precision-- > 0 && nl[i])
			count += ft_putchar(nl[i++]);
	i = 0;
	if (arg != NULL)
		while ((precision--) > 0 && arg[i])
			count += ft_putchar(arg[i++]);
	ft_completion_of_minus_s(width, tmp, tmp_arg, &count);
	return (count);
}

void	ft_completion_of_regular_s(size_t len, int precision, char *arg,
		int *count)
{
	char	*nl;
	int		i;

	nl = "(null)";
	(void)len;
	i = 0;
	if (arg == NULL)
	{
		while (precision-- > 0 && nl[i])
		{
			*count += ft_putchar(nl[i]);
			i++;
		}
	}
	else
	{
		while ((precision--) > 0 && arg[i])
		{
			*count += ft_putchar(arg[i]);
			i++;
		}
	}
}

int	ft_precision_s(char *arg, int precision, int width)
{
	size_t	len;
	int		count;

	len = ft_strlen_printf(arg);
	count = 0;
	if (precision <= (int)len)
		len = (size_t)precision;
	if (precision >= 6 && arg == NULL)
		len = 6;
	if (width && !precision)
	{
		while (width-- > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while (width-- - (int)len > 0)
			count += ft_putchar(' ');
	}
	if (precision >= 6 && arg == NULL)
		count += ft_putstr("(null)");
	else
		ft_completion_of_regular_s(len, precision, arg, &count);
	return (count);
}
