/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_so_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanaf <ahanaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:51:38 by ahanaf            #+#    #+#             */
/*   Updated: 2024/03/27 17:44:15 by ahanaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_words(char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i] && (str[i] != sep))
		{
			count++;
			while (str[i] && !(str[i] == sep))
				i++;
		}
	}
	return (count);
}

void	init_var(int *i, int *index, int *end)
{
	*i = 0;
	*index = 0;
	*end = 0;
}

char	**ft_split_so_long(char *str, t_dimo *dimo, char sep)
{
	int	i;
	int	index;
	int	end;

	init_var(&i, &index, &end);
	dimo->map = (char **)malloc(sizeof(char *) * (count_words(str, sep) + 1));
	if (!dimo->map)
		return (NULL);
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		end = 0;
		while (str[i] && str[i] != sep)
		{
			end++;
			i++;
		}
		dimo->map[index] = ft_substr(str, i - end, end);
		if (!dimo->map[index++])
			return (free_str(dimo->map));
	}
	dimo->map[index] = 0;
	return (dimo->map);
}
