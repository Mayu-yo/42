#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	char ch[1];

	ch[0] = c;
	write(fd,ch,1);
}

int main(){
	ft_putchar_fd('z', 1);
	return 0;
}