/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:28:01 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/05 17:08:02 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

size_t BUFFER_SIZE = 1000;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
// size_t		ft_strlen(const char *str);
// void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
