#include "libft.h"

// int main(){
// 	return 0;
// }

int ft_tolower(int c){
	if('A' <= c && c <= 'Z'){
		return (c + 32);
	}
	return c;
}