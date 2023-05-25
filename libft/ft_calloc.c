/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:23:57 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 08:07:35 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size != 0 && count > SIZE_MAX / size)
        return (NULL);
	mem = (char *)malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

// #include <stdio.h>
// int main() {
//     size_t numElements = 5;
//     size_t elementSize = sizeof(int);
//     // int *arr = (int *)ft_calloc(numElements, elementSize);
//     // if (arr == NULL) {
//     //     printf("メモリの割り当てに失敗しました。\n");
//     //     return 1;
//     // }
// 	int *arr = (int *)ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
//     if (arr == NULL) {
//         printf("メモリの割り当てに失敗しました。\n");
//         return 1;
//     }
// 	// int *arr = (int *)calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
//     // if (arr == NULL) {
//     //     printf("メモリの割り当てに失敗しました。\n");
//     //     return 1;
//     // }

//     // 配列の要素を表示
//     printf("配列の要素：");
//     for (size_t i = 0; i < numElements; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // メモリを解放
//     free(arr);

//     return 0;
// }
