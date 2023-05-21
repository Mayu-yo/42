#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	int len;
	int i;
	char *str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if(str == NULL)
		return (NULL);
	while(s[i] != '\0'){
		str[i] = s[i];
		i++;
	}
	str[i] = '\n';
	write(fd, str, len + 1);
}

int main (){
	ft_putendl_fd("asdfg",1);
	return 0;
}