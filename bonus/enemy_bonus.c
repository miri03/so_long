/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 02:50:08 by meharit           #+#    #+#             */
/*   Updated: 2023/01/30 02:50:10 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	enemy_move_zero(t_data *data, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;	

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy1.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
}

void	enemy_move_one(t_data *data, int x, int y)
{	
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
}

int	animate_enemy(t_data *data)
{
	static int	c;
	t_enemy		*enemy;

	if (c % 6000 != 0)
		return (c++);
	enemy = data->enemy;
	while (enemy)
	{
		if (enemy->m == 0)
		{
			enemy_move_zero(data, enemy->x, enemy->y);
			enemy->m++;
		}
		else
		{
			enemy_move_one(data, enemy->x, enemy->y);
			enemy->m = 0;
		}
		enemy = enemy->next;
	}
	return (c++);
}

void	enemy_right(t_data *data, int x, int y, int *mv)
{	
	void		*img;
	int			img_height;
	int			img_width;

	if (data->map[y][x + 1] == 'P')
		lose_message();
	data->map[y][x] = '0';
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
	x++;
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy1.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
	data->map[y][x] = '+';
	(*mv)++;
}

void	enemy_left(t_data *data, int x, int y, int *mv)
{	
	void		*img;
	int			img_height;
	int			img_width;

	if (data->map[y][x - 1] == 'P')
		lose_message();
	data->map[y][x] = '0';
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
	x--;
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/enemy1.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, x * 60, y * 60);
	data->map[y][x] = '+';
	(*mv)--;
}
