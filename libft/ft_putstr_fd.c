#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int i;
	int len;
	char * str;

	i = 0;
	str = (char *)malloc(len + 1);
	if(str == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	write(fd, str, len);
}

int main (){
	ft_putstr_fd("asdfg",1);
	return 0;
}