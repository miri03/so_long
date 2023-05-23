/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:03:58 by meharit           #+#    #+#             */
/*   Updated: 2023/01/28 15:56:24 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_data *data, char **map)
{
	int	x;
	int	y;
	int	i;
	int	a;

	a = 0;
	y = 0;
	while (map[a] != NULL)
	{
		x = 0;
		i = 0;
		while (map[a][i] != '\0')
		{
			check_it(map[a][i], data, x, y);
			x += 60;
			i++;
		}
		y += 60;
		a++;
	}
}

t_enemy	*get_enemy(char **map)
{
	int		x;
	int		y;
	t_enemy	*enemy;

	enemy = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '+')
			{
				ft_lstadd_back(&enemy, ft_lstnew(x, y));
			}
			x++;
		}
		y++;
	}
	return (enemy);
}

void	so_long(t_data *data, t_param prm)
{
	data->mlx_ptr = mlx_init();
	data->window = mlx_new_window(data->mlx_ptr,
			prm.width * 60,
			prm.height * 60,
			"so_long");
	data->enemy = get_enemy(data->map);
	put_image(data, data->map);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("WELCOME TO MY GAME !\n", 1);
	ft_putstr_fd(RESET, 1);
	mlx_string_put(data->mlx_ptr, data->window, 3, 15, 0x00F5DEB3, "count: 0");
	mlx_key_hook(data->window, key_data, data);
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
