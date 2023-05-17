#include "libft.h"

int main(){
	int ret = 0;
	char *str = "asdf";

	ret = ft_strlen(str);
	printf("%d", ret);
}

size_t ft_strlen(const char *str){
	size_t i = 0;
	while(str != "\0")
	{
		str++;
		i++;
	}
	return (i);
}