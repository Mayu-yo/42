#include "libft.h"

static int	count_word(char const *s, char c)
{
	size_t i;
	int count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (2);
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
		{
			if (i == 0)
				count--;
			
			while (s[i] == c)
				i++;
			if (i == ft_strlen(s))
				count--;
			count++;
		}
		i++;
	}
	return (count + 1);
}

static int	count_word_len(char const *s, char c, size_t i)
{
	int count;

	count = 0;
	while (s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**free_all(char **ret, int j)
{
	while (j >= 0)
	{
		free(ret[j]);
		j--;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t k;
	size_t len;
	char **ret;

	i = 0;
	j = 0;
	k = 0;
	len = count_word(s, c);
	if (!s || !(ret = malloc((len + 1) * sizeof(char *))))
		return (NULL);
	if (s[0] == '\0')
		return (ret = ft_calloc(1, sizeof(char *)));
	if(s[0] == c && c != '\0')
		while (s[i] == c)
			i++;
	ret[0] = (char *)malloc(count_word_len(s, c, i) + 1);
	if (ret == NULL)
		free_all (ret, j);
	while (i <= ft_strlen(s) && s[i] != '\0')
	{
		if (s[i] == c)
		{
			ret[j][k] = '\0';
			while (s[i] == c)
				i++;
			if (s[i] == '\0')
				break;
			j++;
			ret[j] = (char *)malloc(count_word_len(s, c, i));
			if (ret == NULL)
				free_all (ret, j);
			k = 0;
		}
		ret[j][k] = s[i];
		k++;
		i++;
	}
	ret[j][k] = '\0';
	ret[j + 1] = NULL;
	return (ret);
}

// int main(){
// 	ft_split("tripouille", 0);
// 	return 0;
// }
