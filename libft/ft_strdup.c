#include "libft.h"

// #include <stdio.h>
// char *ft_strdup(const char *s);
// int main() {
//     const char* original = "Hello, World!";
//     char* duplicate = ft_strdup(original);

//     if (duplicate != NULL) {
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);
//         free(duplicate);  // メモリの解放
//     }

//     return 0;
// }

char *ft_strdup(const char *s)
{
	size_t len = 0;
	char *dst;
	len = ft_strlen(s);
	if(len == 0)
		return NULL;
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return NULL;
	ft_strlcpy(dst, s, len + 1);
	return dst;
}