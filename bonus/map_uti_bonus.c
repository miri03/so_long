/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_uti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:20:38 by meharit           #+#    #+#             */
/*   Updated: 2023/01/26 22:54:47 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message(char *error)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(RESET, 1);
	exit (1);
}

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	check_top_bottom(char *line)
{
	while (*line)
	{
		if (*line != '1')
			error_message("Not only walls\n");
		line++;
	}
}
