/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:36:43 by meharit           #+#    #+#             */
/*   Updated: 2023/01/28 16:13:37 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/right1.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
	data->x = x / img_width;
	data->y = y / img_height;
}

void	put_exit(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/door.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
	data->x_e = x / img_width;
	data->y_e = y / img_height;
}

int	move_enemy(t_data *data)
{
	t_enemy		*enemy;

	enemy = data->enemy;
	animate_enemy(data);
	if ((data->map[enemy->y][enemy->x + 1] == '0'
		|| data->map[enemy->y][enemy->x + 1] == 'P') && data->c == 5500)
	{
		while (enemy)
		{
			enemy_right(data, enemy->x, enemy->y, &enemy->x);
			enemy = enemy->next;
		}
	}
	else if ((data->map[enemy->y][enemy->x - 1] == '0'
		|| data->map[enemy->y][enemy->x - 1] == 'P') && data->c == 10500)
	{
		while (enemy)
		{
			enemy_left(data, enemy->x, enemy->y, &enemy->x);
			enemy = enemy->next;
		}
		data->c = 0;
	}
	data->c++;
	return (0);
}

void	put_enemy(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy1.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
	data->x_f = x / 60;
	data->y_f = y / 60;
	mlx_loop_hook(data->mlx_ptr, move_enemy, data);
}

void	check_it(char c, t_data *data, int x, int y)
{
	if (c == '1')
		put_wall(data, x, y);
	if (c == 'C')
		put_collec(data, x, y);
	if (c == '0')
		put_grass(data, x, y);
	if (c == 'P')
		put_player(data, x, y);
	if (c == 'E')
		put_exit(data, x, y);
	if (c == '+')
	{
		if (data->map[y / 60][x / 60 + 1] == '0')
			put_enemy(data, x, y);
		else
			error_message("Invalide map : enemy can't move\n");
	}
}
