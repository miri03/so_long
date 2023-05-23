/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:00:54 by meharit           #+#    #+#             */
/*   Updated: 2023/01/27 02:06:46 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moving_utiliti(int *x, int *y, t_data *data, int c)
{
	*y = data->x;
	*x = data->y;
	if (data->map[*x][*y] != 'E')
		data->map[*x][*y] = 'P';
	if (data->collec == c)
		change_door(data);
	if (data->map[*x][*y] == 'E')
		exit_message();
}

void	lose_message(void)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd("YOU LOST 😅\n", 1);
	ft_putstr_fd(RESET, 1);
	exit(0);
}

void	moving(int c_x, int c_y, t_data *data, int *c)
{
	int	x;
	int	y;
	int	n_x;
	int	n_y;

	x = data->y;
	y = data->x;
	n_x = c_x + x;
	n_y = c_y + y;
	if (data->map[n_x][n_y] == '+' || data->map[n_x][n_y] == '0'
		|| data->map[n_x][n_y] == 'C' ||
		(data->map[n_x][n_y] == 'E' && data->collec == *c))
	{
		in_window(data, "./textures/floor.xpm");
		data->map[x][y] = '0';
		data->x = data->x + c_y;
		data->y = data->y + c_x;
		if (data->map[n_x][n_y] == 'C')
			(*c)++;
		if (data->map[n_x][n_y] == '+')
			lose_message();
		(in_window_player(data, c_x, c_y), moving_utiliti(&x, &y, data, *c));
	}
}

void	move_player(int keycode, t_data *data)
{
	static int	c;

	if (keycode == RIGHT || keycode == RIGHT_D)
		moving(0, 1, data, &c);
	if (keycode == LEFT || keycode == LEFT_A)
		moving(0, -1, data, &c);
	if (keycode == UP || keycode == UP_W)
		moving(-1, 0, data, &c);
	if (keycode == DOWN || keycode == DOWN_S)
		moving(1, 0, data, &c);
}

int	key_data(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->window);
		ft_putstr_fd("YOU QUITED THE GAME\n", 1);
		exit(0);
	}
	else
		move_player(keycode, data);
	return (0);
}
