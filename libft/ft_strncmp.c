#include "libft.h"

// int main(){
// 	return 0;
// }
int ft_strncmp(const char *s1, const char *s2, size_t n){
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		ret = s1[i] - s2[i];
		if (ret != 0)
		{
			return (ret);
		}
		i++;
	}
	return (0);
}