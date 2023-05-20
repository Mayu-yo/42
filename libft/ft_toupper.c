#include "libft.h"

// int main(){
// 	return 0;
// }

int ft_toupper(int c){
	if('a' <= c && c <= 'z'){
		return (c - 32);
	}
	return c;
}