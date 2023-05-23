/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_uti_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:25:35 by meharit           #+#    #+#             */
/*   Updated: 2023/01/27 06:25:04 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	in_window(t_data *data, char *path)
{
	int			img_width;
	int			img_height;
	void		*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr, data->window,
		img, data->x * img_width, data->y * img_height);
}

void	counter(int count, t_data *data)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*counter;

	img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/tree.xpm", &img_width, &img_height);
	if (img == NULL)
		error_message("Invalide image");
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, img, 60, 0);
	counter = ft_itoa(count);
	mlx_string_put(data->mlx_ptr, data->window, 79, 15, 0x00F5DEB3, counter);
	free(counter);
}

void	player_movement(int m, t_data *data, char *img0, char *img1)
{
	if (m == 0)
		in_window(data, img0);
	if (m == 1)
		in_window(data, img1);
}

void	in_window_player(t_data *data, int x, int y)
{
	static int	m;
	static int	count;

	if (y == 1)
		player_movement(m, data, "./textures/right1.xpm",
			"./textures/right2.xpm");
	else if (y == -1)
		player_movement(m, data, "./textures/left1.xpm",
			"./textures/left2.xpm");
	else if (x == -1)
		player_movement(m, data, "./textures/up1.xpm",
			"./textures/up2.xpm");
	else if (x == 1)
		player_movement(m, data, "./textures/up1.xpm",
			"./textures/up2.xpm");
	m++;
	if (m == 2)
		m = 0;
	count++;
	counter(count, data);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window);
	ft_putstr_fd("YOU QUITED THE GAME\n", 1);
	exit(0);
}
