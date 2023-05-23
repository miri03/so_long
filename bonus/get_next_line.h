/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meharit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:15 by meharit           #+#    #+#             */
/*   Updated: 2022/11/18 09:09:59 by meharit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<unistd.h>
# include<stdlib.h>

char	*get_next_line(int fd, char **line, int height);
char	*ft_strjoin(char *s1, char *s2);
int		new_line(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
