#include "libft.h"

// #include <stdio.h>
// char *ft_strjoin(char const *s1, char const *s2);
// size_t ft_strlen(const char *str){
// 	size_t i = 0;
// 	while(*str != '\0')
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }
int main(){
	char *ret;
	ret = ft_strjoin("qwert","asdfg");
	printf("%s",ret);
	return 0;
}

char *ft_strjoin(char const *s1, char const *s2){
	int i = 0;
	int j = 0;
	char * s;
	int len = ft_strlen(s1);
	len += ft_strlen(s2);
	s = (char *)malloc(len + 1);
	if(s = NULL)
		return NULL;
	while (s1[i] != '\0'){
		s[i] = s1[i];
		i++;
	}
	while(s2[j] != '\0'){
		s[i+j] = s2[j];
		j++;
	}
	s[i+j] = '\0';
	return s;
}