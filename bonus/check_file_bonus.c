/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 02:54:41 by meharit           #+#    #+#             */
/*   Updated: 2023/01/30 02:54:44 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_ber(char *p_file, int len)
{
	if (len == 3)
		error_message("Error : invalid file\n");
	if (p_file[len] == 'r' && p_file[len - 1] == 'e' && p_file[len - 2] == 'b'
		&& p_file[len - 3] == '.')
	{
		if (p_file[len - 4] == '/')
			error_message("Error : invalid file\n");
	}
	else
		error_message("Error : invalid file\n");
}

void	check_file(char *p_file)
{
	int	len;
	int	fd;

	len = ft_strlen(p_file) - 1;
	fd = open(p_file, O_RDWR);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror("Error");
		exit(1);
	}
	check_ber(p_file, len);
	close(fd);
}
