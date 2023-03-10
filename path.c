/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:33:16 by meharit           #+#    #+#             */
/*   Updated: 2023/01/26 22:50:01 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valide_collec(char **map, int x, int y, t_check *c_e)
{
	if (map[x][y] == 'P' || map[x][y] == '0')
	{
		map[x][y] = 'X';
	}
	else if (map[x][y] == 'C')
	{
		map[x][y] = 'X';
		(c_e->c)++;
	}
	else if (map[x][y] == '1' || map[x][y] == 'X' || map[x][y] == 'E')
		return ;
	valide_collec(map, x, y + 1, c_e);
	valide_collec(map, x - 1, y, c_e);
	valide_collec(map, x, y - 1, c_e);
	valide_collec(map, x + 1, y, c_e);
}

void	valide_exit(char **map, int x, int y, t_check *c_e)
{
	if (map[x][y] == 'P' || map[x][y] == '0' || map[x][y] == 'C')
	{
		map[x][y] = 'X';
	}
	else if (map[x][y] == 'E')
	{
		map[x][y] = 'R';
		c_e->e = 1;
	}	
	else if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	valide_exit(map, x, y + 1, c_e);
	valide_exit(map, x - 1, y, c_e);
	valide_exit(map, x, y - 1, c_e);
	valide_exit(map, x + 1, y, c_e);
}

char	**make_copy(char **map, t_pos *pos, t_param prm)
{
	char	**copy;
	int		i;
	int		y;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (prm.height + 1));
	while (map[i] != NULL)
	{
		y = 0;
		while (map[i][y] != '\0')
		{
			if (map[i][y] == 'P')
			{
				pos->p_x = i;
				pos->p_y = y;
			}
			y++;
		}
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
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

void	check_path(char **map, t_pos *pos, t_param prm, t_char chr)
{
	char	**copy;
	t_check	c_e;

	c_e.e = 0;
	c_e.c = 0;
	copy = make_copy(map, pos, prm);
	valide_collec(copy, pos->p_x, pos->p_y, &c_e);
	free_copy(copy);
	free(copy);
	if (c_e.c == chr.collec)
	{
		copy = make_copy(map, pos, prm);
		valide_exit(copy, pos->p_x, pos->p_y, &c_e);
		if (c_e.e == 0)
			error_message("Path invalide for exit\n");
	}
	else if (c_e.c < chr.collec)
		error_message("Path invalide for collecs\n");
	free_copy(copy);
	free(copy);
}
