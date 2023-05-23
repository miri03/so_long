/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:00:12 by meharit           #+#    #+#             */
/*   Updated: 2023/01/29 21:35:01 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"
# include <stdio.h>

# define RED "\033[0;31m"
# define PURPLE "\033[0;35m"
# define BLUE "\033[0;36m"
# define RESET "\033[0m"
# define GREEN "\033[0;32m"

enum	e_keys
{
	ESC = 53,
	RIGHT = 124,
	RIGHT_D = 2,
	LEFT = 123,
	LEFT_A = 0,
	UP_W = 13,
	UP = 126,
	DOWN = 125,
	DOWN_S = 1
};

typedef struct position
{
	int	p_x;
	int	p_y;

	int	c_x;
	int	c_y;

	int	e_x;
	int	e_y;	
}			t_pos;

typedef struct check
{
	int	c;
	int	e;
}			t_check;

typedef struct parametere
{
	int	height;
	int	width;
}			t_param;

typedef struct charac
{
	int	exit;
	int	player;
	int	collec;
	int	enemy;
}			t_char;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window;
	int		x;
	int		x_e;
	int		y;
	int		y_e;
	int		collec;
	char	**map;

}			t_data;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_param	check_map(char *p_map, t_char *chr, t_data *data);
char	*get_next_line(int fd, char **line, int height);
void	check_path(char **map, t_pos *pos, t_param prm, t_char chr);
void	error_message(char *error);
int		key_data(int keycode, t_data *data);
int		ft_close(t_data *data);
void	put_image(t_data *data, char **map);
char	**make_map(int fd, t_param prm);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	put_wall(t_data *data, int x, int y);
void	put_collec(t_data *data, int x, int y);
void	exit_message(void);
void	change_door(t_data *data);
void	error_message(char *error);
int		ft_len(char *str);
void	check_top_bottom(char *line);
void	in_window(t_data *data, char *path);
void	player_movement(int m, t_data *data, char *img0, char *img1);
void	counter(int count);
void	in_window_player(t_data *data, int x, int y);

#endif
