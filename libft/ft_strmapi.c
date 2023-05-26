/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:04:33 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 22:00:38 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = f(i,s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// char uppercase_char(unsigned int index, char c) {
//     // 文字がアルファベットの小文字であれば、大文字に変換する
//     if (c >= 'a' && c <= 'z') {
//         return c - ('a' - 'A');
//     }
//     return c;
// }

// #include <stdio.h>
// int main() {
//     const char *s = "Hello, World!";
//     char *result = ft_strmapi(s, uppercase_char);
//     if (result != NULL) {
//         printf("%s\n", result);  // "HELLO, WORLD!"
//         free(result);  // メモリを解放する
//     }
//     return 0;
// }
