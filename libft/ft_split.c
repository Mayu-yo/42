#include "libft.h"

#include <stdio.h>
int main(){
	char **ret;
	ret = ft_split("a1sg12sd2", 1);
	printf("%s", ret[0]);
	return 0;
}

char **ft_split(char const *s, char c){
	char **ret;
	int i = 0;
	int j = 0;
	int flag = 0;
	while(*s != '\0'){
		ret[i][j] = *s;
		if(*s == c && flag == 0){//初めて区切り文字が出現した場合
			flag = 1;
			i++;
			s++;
			j = 0;
		}else if(*s == c && flag == 1){//前の文字も区切り文字だった場合
			s++;
		}else{
			flag = 0;
			s++;
			j++;
		}
	}
	return ret;
}