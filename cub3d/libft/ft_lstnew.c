/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:52:19 by mayyamad          #+#    #+#             */
/*   Updated: 2023/06/03 18:26:45 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next_node;

	next_node = (t_list *)malloc(sizeof(t_list) * 1);
	if (next_node == NULL)
		return (NULL);
	next_node->content = content;
	next_node->next = NULL;
	return (next_node);
}
