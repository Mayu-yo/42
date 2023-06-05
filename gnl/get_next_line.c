#include <unistd.h>

size_t BUFFER_SIZE 1000;

static char *ft_read_line(int fd)
{
	int flag;
	char *buf;

	flag = read(fd, buf, BUFFER_SIZE);//bufにBUFFER _SIZE分読み込み
	if (flag == -1)
	{
		free(buf);
		return (NULL);
	}
}

char get_next_line(int fd)
{
	char *left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_line(fd);
	return ();
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}