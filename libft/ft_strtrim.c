#include "libft.h"

// size_t ft_strlen(const char *str){
// 	size_t i = 0;
// 	while(*str != '\0')
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }
// char *ft_strtrim(char const *s1, char const *set);
#include <stdio.h>
int main(){
	char *ret;
	ret = ft_strtrim("qtyuqwet", "tdu");
	printf("%s",ret);
	free (ret);
	return 0;
}

char *ft_strtrim(char const *s1, char const *set){
	char *ret;
	ret = (char *)malloc(ft_strlen(s1));
	int j = 0;
	int i = 0;
	int flag = 0;
	if (ret == NULL)
	 	return NULL;
	while (*s1 != '\0'){
		i = 0;
		while(set[i] != '\0'){
			if(*s1 == set[i]){
				flag = 0;
				break;
			}else if(set[i+1] == '\0'){
				ret[j] = *s1;
				j++;
				flag = 1;
			}
			i++;
		}
		s1++;
	}
	if(flag == 1)
		ret[j] = '\0';
	else
		ret[j+1] = '\0';
	return ret;
}