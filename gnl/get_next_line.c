#include "get_next_line.h"

#include <stdio.h>
size_t BUFFER_SIZE = 1000;

static char *ft_read_line(int fd)
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
		read_byte = read(fd, buf, BUFFER_SIZE); // bufにBUFFER _SIZE分読み込み
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		line = ft_strjoin(line, buf);
		line[read_byte] = '\0';
	}
	return (line);
}

char *get_next_line(int fd)
{
	char *line;
	static char *save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		line = save;
		save = ft_strchr(line, '\n');
		return (line);
	}
	line = ft_read_line(fd);
	save = ft_strchr(line, '\n');
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
		printf("line [%02d]: %s", i, line);
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