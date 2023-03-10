/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_uti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:22:23 by meharit           #+#    #+#             */
/*   Updated: 2023/01/26 19:46:02 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_line(char *tmp, t_param prm)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *) malloc(sizeof(char) * (prm.width + 1));
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**make_map(int fd, t_param prm)
{
	int		index;
	char	*tmp;
	char	**line;

	index = 0;
	line = (char **)malloc(sizeof(char *) * (prm.height + 1));
	while (get_next_line(fd, &tmp, -1))
	{
		line[index] = fill_line(tmp, prm);
		index++;
		free(tmp);
	}
	line[index] = NULL;
	index = 0;
	return (line);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL && fd >= 0)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
