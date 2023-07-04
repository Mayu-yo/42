/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:36:57 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/29 22:45:20 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_next(buffer);
	return (line);
}

char	*read_file(char *dst, int fd)
{
	char	*tmp;
	int		byteread;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	byteread = 1;
	while (byteread > 0 && !(ft_strchr(tmp, '\n')))
	{
		byteread = read(fd, tmp, BUFFER_SIZE);
		if (byteread < 0)
			return (ft_free(dst, tmp));
		if (byteread > 0)
		{
			tmp[byteread] = 0;
			dst = ft_strjoin(dst, tmp);
		}
		if (dst == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free (tmp);
	return (dst);
}

char	*get_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (i == 0 && buffer[i] == 0)
		return (NULL);
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	return (line);
}

char	*get_next(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	next = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!next)
		return (NULL);
	while (buffer[i + j] != 0)
	{
		next[j] = buffer[i + j];
		j++;
	}
	next[j] = 0;
	free(buffer);
	return (next);
}

char	*ft_free(char *dst, char *tmp)
{
	free(dst);
	free(tmp);
	return (NULL);
}
