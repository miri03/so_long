/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 06:43:22 by meharit           #+#    #+#             */
/*   Updated: 2023/01/27 06:47:05 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*ft_lstnew(int x, int y)
{
	t_enemy	*new;

	new = (t_enemy *)malloc(sizeof(t_enemy));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->m = 0;
	new->next = NULL;
	return (new);
}

t_enemy	*ft_lstlast(t_enemy *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
