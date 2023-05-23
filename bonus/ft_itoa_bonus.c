/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:58:27 by meharit           #+#    #+#             */
/*   Updated: 2023/01/27 06:22:46 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_size(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		i;
	long	nb;

	nb = (long) n;
	i = 0;
	size = ft_size(nb);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[size] = '\0';
	if (nb < 0)
	{
		i++;
		ptr[0] = '-';
		nb *= -1;
	}
	while (i <= size - 1)
	{
		ptr[size - 1] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
	return (ptr);
}
