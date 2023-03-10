/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:03:58 by meharit           #+#    #+#             */
/*   Updated: 2023/01/29 21:40:04 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	check_ber(char *p_file, int len)
{
	if (len == 3)
		error_message("Error : invalid file\n");
	if (p_file[len] == 'r' && p_file[len - 1] == 'e'
		&& p_file[len - 2] == 'b' && p_file[len - 3] == '.')
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

void	so_long(t_data *data, t_param prm)
{
	data->mlx_ptr = mlx_init();
	data->window = mlx_new_window(data->mlx_ptr,
			prm.width * 60, prm.height * 60, "so_long");
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("WELCOME TO MY GAME !\n", 1);
	ft_putstr_fd(RESET, 1);
	put_image(data, data->map);
	mlx_hook(data->window, 2, 0, key_data, data);
	mlx_hook(data->window, 17, 0, ft_close, data);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_param	prm;
	t_data	data;
	t_pos	pos;
	t_char	chr;

	data.map = NULL;
	if (argc != 2)
		error_message("not enough arguments\n");
	check_file(argv[1]);
	prm = check_map(argv[1], &chr, &data);
	fd = open(argv[1], O_RDONLY);
	data.map = make_map(fd, prm);
	close(fd);
	check_path(data.map, &pos, prm, chr);
	so_long(&data, prm);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
}
