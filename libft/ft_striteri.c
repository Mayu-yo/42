/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:47:04 by mayyamad          #+#    #+#             */
/*   Updated: 2023/05/25 22:04:16 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// // 文字列の各文字に対してインデックスを出力する関数
// void printIndex(unsigned int index, char *ch) {
//     printf("Character at index %d is '%c'\n", index, *ch);
// }

// // 文字列の各文字を大文字に変換する関数
// void toUpperCase(unsigned int index, char *ch) {
//     if (*ch >= 'a' && *ch <= 'z') {
//         *ch = *ch - 'a' + 'A';
//     }
// }

// int main() {
//     char str[] = "Hello, World!";

//     printf("Original string: %s\n", str);

//     // 文字列の各文字に対してインデックスを出力する関数を適用
//     ft_striteri(str, printIndex);

//     // 文字列の各文字を大文字に変換する関数を適用
//     ft_striteri(str, toUpperCase);

//     printf("Modified string: %s\n", str);

//     return 0;
// }
