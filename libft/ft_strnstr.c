#include "libft.h"

int main()
{
	char a[] = "qwert";
	char b[] = "wr";
	char *ret;
	ret = ft_strnstr(a, b, 3);
	write(1, ret, sizeof(ret));
	return 0;
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t needle_len = ft_strlen(needle);
    size_t haystack_len = ft_strlen(haystack);
    
    if (needle_len == 0)
        return (char *)haystack;
    
    if (len < needle_len || haystack_len < needle_len)
        return NULL;
    
    for (size_t i = 0; i <= haystack_len - needle_len && i <= len - needle_len; i++)
    {
        if (ft_strncmp(haystack + i, needle, needle_len) == 0)
            return (char *)(haystack + i);
    }
    return NULL;
}
