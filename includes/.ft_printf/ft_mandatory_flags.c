/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:11:05 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:54:09 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mandatory_flags(char f)
{
	if (f == 'p')
		return (1);
	if (f == 'd')
		return (1);
	if (f == 'i')
		return (1);
	if (f == 'u')
		return (1);
	if (f == 'x')
		return (1);
	if (f == 'X')
		return (1);
	if (f == 's')
		return (1);
	if (f == 'c')
		return (1);
	if (f == '%')
		return (1);
	return (0);
}
