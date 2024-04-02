/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:51:59 by ahanaf            #+#    #+#             */
/*   Updated: 2024/01/05 09:54:13 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// end +1 to included the formats by example %
// -+d in this case we add 1 to end to include d
char	*ft_parser(const char *str, int start, int end)
{
	char	*prs;
	int		i;

	prs = (char *)malloc(sizeof(char) * ((end + 1) - start + 1));
	if (!prs)
		return (NULL);
	i = 0;
	while (i <= end - start)
	{
		prs[i] = str[start + i];
		i++;
	}
	prs[i] = '\0';
	return (prs);
}
