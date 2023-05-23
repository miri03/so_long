/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_uti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:47:48 by meharit           #+#    #+#             */
/*   Updated: 2023/01/27 07:47:03 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_wall(t_data *data, int x, int y)
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
			"./textures/tree.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
}

void	put_collec(t_data *data, int x, int y)
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
			"./textures/fruit.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, x, y);
}

void	change_door(t_data *data)
{
	static int	m;
	int			img_width;
	int			img_height;
	void		*img;

	if (m == 0)
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr,
				"./textures/door_opened.xpm", &img_width, &img_height);
		if (img == NULL)
			error_message("Invalide image");
		mlx_put_image_to_window(data->mlx_ptr, data->window, img,
			data->x_e * img_width, data->y_e * img_height);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd(BLUE, 1);
		ft_putstr_fd("YOU OPENED THE GATE!!!\n", 1);
		ft_putstr_fd(RESET, 1);
		ft_putchar_fd('\n', 1);
	}
	m++;
}

void	put_grass(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window, img, x, y);
}

void	exit_message(void)
{
	ft_putstr_fd(BLUE, 1);
	ft_putstr_fd("YOU WIN!!!!!\n", 1);
	ft_putstr_fd(RESET, 1);
	exit(0);
}
