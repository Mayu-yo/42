#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

static char *ft_read_line(int fd)
{
	ssize_t flag;
	char *buf;
	char *line;

	line = NULL;
	while ()
	{
		flag = read(fd, buf, BUFFER_SIZE); // bufにBUFFER _SIZE分読み込み
		if (flag == -1)
		{
			free(buf);
			return (NULL);
		}
		new_func(line, buf);
	}
	return buf;
}

char *get_next_line(int fd)
{
	char *left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = ft_read_line(fd);
	return (left);
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