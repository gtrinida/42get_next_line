/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:21:28 by gtrinida          #+#    #+#             */
/*   Updated: 2021/11/19 16:08:34 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_with_end(char **line, int byte_was_read)
{
	if (byte_was_read <= 0)
	{
		free(*line);
		*line = 0;
	}
	return (NULL);
}

char	*ft_new_line(char **remainder, char **line)
{
	char	*n_pointer;

	n_pointer = NULL;
	if (*remainder)
	{
		n_pointer = ft_strchr(*remainder, '\n');
		if (n_pointer)
		{
			*line = ft_strdup_extra(*remainder, 1);
			ft_strcpy(*remainder, ++n_pointer);
		}
		else
		{
			*line = ft_strdup_extra(*remainder, 1);
			free(*remainder);
			*remainder = 0;
		}
	}
	else
	{
		*line = malloc(sizeof(char));
		*line[0] = '\0';
	}
	return (n_pointer);
}

char	*ft_free(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	if (!(*line))
		return (NULL);
	return (*line);
}

int	ft_read(int fd, int *bwr, char *buf, char **line)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		ft_free_with_end(line, *bwr);
	*bwr = read(fd, buf, BUFFER_SIZE);
	return (*bwr);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				byte_was_read;
	char			*n_pointer;
	static char		*remainder;

	byte_was_read = 1;
	n_pointer = ft_new_line(&remainder, &line);
	while (!n_pointer && ft_read(fd, &byte_was_read, buf, &line) > 0)
	{
		buf[byte_was_read] = '\0';
		n_pointer = ft_strchr(buf, '\n');
		if (n_pointer)
		{
			remainder = ft_strdup_extra(++n_pointer, 0);
			*n_pointer = '\0';
		}
		line = ft_free(&line, buf);
		if (!(*line))
			return (NULL);
	}
	if (byte_was_read <= 0 && *line == 0)
		return (ft_free_with_end(&line, byte_was_read));
	return (line);
}

//#include <string.h>
//#include <stdio.h>
//
//void check(int a)
//{
//    if (a)
//        puts("Eto horosho!\n");
//}
//
//void gnl(int fd, char const *expectedReturn)
//{
//    char *  gnlReturn = get_next_line(fd);
//    printf("???????? ?????????????? ??????????????: [%s]\n", gnlReturn);
//    if (expectedReturn == NULL)
//        check(gnlReturn == NULL);
//    else
//    {
//        check(!strcmp(gnlReturn, expectedReturn));
//    }
//    free(gnlReturn);
//}
//
//int	main(void)
//{
//    int		fd;
//	fd = open("/Users/gtrinida/CLionProjects/42gnl/gnlTester/files/multiple_nlx5", O_RDWR);
//	gnl(fd, "\n");
//	gnl(fd, "\n");
//	gnl(fd, "\n");
//	gnl(fd, "\n");
//	gnl(fd, "\n");
//	gnl(fd, NULL);
//    close(fd);
//}
