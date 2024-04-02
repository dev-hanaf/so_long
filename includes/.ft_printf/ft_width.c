/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:26:04 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:55:18 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(char *prs)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (prs[i])
	{
		if (prs[i] == '.')
			return (width);
		if (ft_isdigit(prs[i]))
		{
			if (width == 0 && prs[i] == 48)
			{
				i++;
				continue ;
			}
			width = width * 10 + (prs[i] - '0');
			if (!ft_isdigit(prs[i + 1]))
				return (width);
		}
		i++;
	}
	return (width);
}
