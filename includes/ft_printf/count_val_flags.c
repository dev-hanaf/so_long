/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_val_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:56:18 by new               #+#    #+#             */
/*   Updated: 2024/01/05 09:53:21 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_val_flags(t_val *flag)
{
	int	counter;

	counter = 0;
	if (flag->precision)
		counter++;
	if (flag->zero)
		counter++;
	if (flag->minus)
		counter++;
	if (flag->plus)
		counter++;
	if (flag->space)
		counter++;
	if (flag->hash)
		counter++;
	if (flag->number)
		counter += flag->number;
	return (counter);
}
