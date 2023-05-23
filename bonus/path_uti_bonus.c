/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_uti_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 02:49:57 by meharit           #+#    #+#             */
/*   Updated: 2023/01/30 02:50:01 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*fill_in(char *map, t_param prm, t_pos *pos, int y)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (prm.width + 1));
	while (map[i])
	{
		if (map[i] == 'P')
		{
			pos->p_x = y;
			pos->p_y = i;
		}
		if (map[i] == '+' && map[i + 1] == '0')
		{
			copy[i] = '0';
			i++;
			copy[i] = '+';
		}
		else
			copy[i] = map[i];
		i++;
	}
	return (copy);
}

char	**make_copy1(char **map, t_pos *pos, t_param prm)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (prm.height + 1));
	while (map[i] != NULL)
	{
		while (map[i])
		{
			copy[i] = fill_in(map[i], prm, pos, i);
			i++;
		}
	}
	return (copy);
}

void	free_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i] != NULL)
	{
		free(copy[i]);
		i++;
	}
}
