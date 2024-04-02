/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:29:55 by ahanaf            #+#    #+#             */
/*   Updated: 2024/04/01 21:54:32 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	if (!s)
		return 0;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
size_t	ft_strlen_without_nl(const char *s)
{
	size_t	i;
	if (!s)
		return 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
