#include "libft.h"

#include <stdio.h>
int main() {
    // テスト用の配列の要素数と要素のサイズ
    size_t numElements = 5;
    size_t elementSize = sizeof(int);

    // ft_calloc を使用してメモリを割り当て
    int *arr = (int *)ft_calloc(numElements, elementSize);
    if (arr == NULL) {
        printf("メモリの割り当てに失敗しました。\n");
        return 1;
    }

    // 配列の要素を表示
    printf("配列の要素：");
    for (size_t i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // メモリを解放
    free(arr);

    return 0;
}

void *ft_calloc(size_t count, size_t size){
	void *mem = (char *)malloc(count * size);
	if(mem == NULL)
		return NULL;
	ft_memset(mem, 0, count * size);
	return mem;
}