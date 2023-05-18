#include "libft.h"

int main(){
	return 0;
}

int ft_tolower(int c){
	if(66 <= c && c <= 90){
		return (c + 32);
	}
	return c;
}