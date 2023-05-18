#include "libft.h"

int main(){
	char a[] = "qwert";
	char b[] = "wr";
	char *ret;
	ret = ft_strnstr(a,b,3);
	write(1,ret,sizeof(ret));
	return 0;
}

char *ft_strnstr(const char *haystack, const char *needle, size_t slen){
	char c, sc;
	size_t len;

	if ((c = * needle++) != '\0') {
		len = ft_strlen( needle);
		while (ft_strncmp(haystack,  needle, len) != 0){
			while (sc != c){
				if (slen-- < 1 || (sc = *haystack++) == '\0')
					return (NULL);
			}
			if (len > slen)
				return (NULL);
		}
		haystack--;
	}
	return ((char *)haystack);
}