/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:36:43 by meharit           #+#    #+#             */
/*   Updated: 2023/01/26 19:48:21 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_grass(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
}

void	put_player(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/right1.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
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
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/door.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
		data->x_e = x / img_width;
		data->y_e = y / img_height;
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
}

void	put_image(t_data *data, char **map)
{
	int		x;
	int		y;
	int		i;
	int		a;

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
