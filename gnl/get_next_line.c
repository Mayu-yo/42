#include "get_next_line.h"

#include <stdio.h>
size_t BUFFER_SIZE = 1000;

static char *ft_read_all(int fd)
{
	ssize_t read_byte;
	char *buf;
	char *line;

	line = NULL;
	read_byte = 1;
	while (!(ft_strchr(line, '\n')) && read_byte != 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1 ||read_byte == 0)
		{
			free(buf);
			return (line);
		}
		line = ft_strjoin(line, buf);
		free(buf);
		line[read_byte] = '\0';
	}
	return (line);
}

char *ft_get_line(char *buf, char *ret)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if(!buf || buf[0] == '\0')
		return (NULL);
	if (buf[0] == '\n')
	{
		ret = malloc(1);
		return (ret);
	}
	while (buf[i] != '\n' && buf[i])
	{
		len++;
		i++;
	}
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, buf, len + 1);
	return (ret);
}

char *get_next_line(int fd)
{
	char *buf;
	char *line;
	char *p;
	static char *save;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save && *save != '\0')
	{
		buf = ft_strjoin(buf, save + 1);
		line = ft_get_line(buf, line);
		p = ft_strchr(buf, '\n');
		free (save);
		save = NULL;
		if(p)
			save = ft_strjoin(save, p);
		free(buf);
		return (line);
	}
	buf = ft_read_all(fd);//malloc
	if (!buf)
		return (NULL);
	line = ft_get_line(buf, line);//malloc
	p = ft_strchr(buf, '\n');
	if(p)
		save = ft_strjoin(save, p);//malloc
	free(buf);
	return (line);
}

#include <fcntl.h>
int main(void)
{
	char *line;
	int i;
	int fd1;
	// int		fd2;
	// int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	// fd2 = open("tests/test2.txt", O_RDONLY);
	// fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	// close(fd2);
	// close(fd3);
	return (0);
}