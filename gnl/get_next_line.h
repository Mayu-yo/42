/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:28:01 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/06 00:16:39 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>


// size_t BUFFER_SIZE = 1000;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
// size_t		ft_strlen(const char *str);
// void		*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
