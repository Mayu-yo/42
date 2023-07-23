/* *********************************************************************** *** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:12:15 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/10 00:52:09 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
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
	line = get_next_line(fd1);
	while (line)
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		line = get_next_line(fd1);
		i++;
	}
	close(fd1);
	system("leaks -q a.out");
	// close(fd2);
	// close(fd3);
	return (0);
}