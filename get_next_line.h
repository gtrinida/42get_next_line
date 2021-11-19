/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:38:20 by gtrinida          #+#    #+#             */
/*   Updated: 2021/11/19 15:43:25 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strcpy(char *dst, const char *src);
char		*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif