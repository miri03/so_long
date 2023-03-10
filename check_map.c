/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:33:54 by meharit           #+#    #+#             */
/*   Updated: 2023/01/29 21:35:44 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_characters(char c, t_char *chr, int pos, int len)
{
	if ((pos == 0 || pos == (len - 1)) && c != '1')
		error_message("|not a wall at beginning or end|\n");
	if (c == 'E')
	{
		if (chr->exit == 0)
			(chr->exit)++;
		else
			error_message("|more than one exit|\n");
	}
	if (c == 'P')
	{
		if (chr->player == 0)
			(chr->player)++;
		else
			error_message("|more than one player|\n");
	}
	if (c == 'C')
		chr->collec++;
}

void	check_line(char *line, t_char *chr, int width)
{
	int	pos;
	int	len;

	len = ft_len(line);
	pos = 0;
	if (width != len)
		error_message("|not rec|\n");
	while (line[pos])
	{
		if (line[pos] == 'E' || line[pos] == '1' || line[pos] == '0'
			|| line[pos] == 'P' || line[pos] == 'C')
			check_characters(line[pos], chr, pos, len);
		else
			error_message("|invalid character|\n");
		pos++;
	}
}

void	height_map(t_param *prm, char *p_map, t_char *chr)
{
	int		fd;
	char	*line;

	line = NULL;
	prm->height = 0;
	chr->collec = 0;
	chr->exit = 0;
	chr->player = 0;
	fd = open(p_map, O_RDONLY);
	while (get_next_line(fd, &line, -1) != NULL)
	{
		(prm->height)++;
		free(line);
	}
	close(fd);
}

void	error_p_e_c(t_char *chr, t_param prm)
{
	if (prm.height == 1 || prm.height == 0)
		error_message("invalid map\n");
	if (chr->collec == 0 || chr->exit == 0 || chr->player == 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (chr->collec == 0)
			ft_putstr_fd("NO COLLECTIBLES\n", 2);
		if (chr->exit == 0)
			ft_putstr_fd("NO EXIT\n", 2);
		if (chr->player == 0)
			ft_putstr_fd("NO PLAYER\n", 2);
		exit(1);
	}
}

t_param	check_map(char *p_map, t_char *chr, t_data *data)
{
	char	*line;
	int		nb_line;
	t_param	prm;
	int		fd;

	nb_line = 1;
	height_map(&prm, p_map, chr);
	fd = open(p_map, O_RDONLY);
	while (get_next_line(fd, &line, prm.height) != NULL)
	{
		if (nb_line == 1 || nb_line == prm.height)
		{
			if (nb_line == 1)
				prm.width = ft_len(line);
			check_top_bottom(line);
			nb_line++;
		}
		else
			check_line(line, chr, prm.width);
		free(line);
	}
	error_p_e_c(chr, prm);
	data->collec = chr->collec;
	return (prm);
}
