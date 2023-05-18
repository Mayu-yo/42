#include "libft.h"

int main(){
	return 0;
}

void *ft_calloc(size_t count, size_t size){
	void *mem = (char *)malloc(count * size);
	if(mem == NULL)
		return NULL;
	ft_memset(mem, 0, count * size);
	return mem;
}