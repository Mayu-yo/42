/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:26:25 by susami            #+#    #+#             */
/*   Updated: 2023/05/24 16:13:36 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	/* 1 */ ASSERT_EQ_STR(ft_strtrim("hello world", "world"), "hello ");
	/* 2 */ ASSERT_EQ_STR(ft_strtrim("hello world", "hello"), " world");
	/* 3 */ ASSERT_EQ_STR(ft_strtrim("hello world", ""), "hello world");
	/* 4 */ ASSERT_EQ_STR(ft_strtrim("", ""), "");
	/* 5 */ ASSERT_EQ_STR(ft_strtrim("    hello world     ", " "), "hello world");
	/* 6 */ ASSERT_EQ_STR(ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n", " \n\t\r"), "hello \n\t\r world");
	/* 7 */ ASSERT_EQ_STR(ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz"), " ");
}
