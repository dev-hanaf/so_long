/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 00:03:03 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:54:05 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_precision(char *prs)
{
	int	precision;
	int	i;

	precision = 0;
	i = 0;
	while (prs[i] != '.')
		i++;
	i++;
	while (prs[i])
	{
		if (ft_isdigit(prs[i]))
			precision = precision * 10 + (prs[i] - '0');
		i++;
	}
	return (precision);
}
