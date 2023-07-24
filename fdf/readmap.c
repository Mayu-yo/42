#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

void read_map_file(char *line, int **coordinate){
	int x;
	static int	y;

	x = 0;
	while (line[x]){
		coordinate[x][y] = line[x];
		x++;
	}
}

int	read_map(char *file_name){//引数はファイル名？
	char *line;
	int i;
	int fd1;
	fd1 = open(file_name, O_RDONLY);
	i = 1;
	line = get_next_line(fd1);
	while (line)
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd1);
		i++;
	}
	close(fd1);
	return (0);
}