/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:54:20 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/10 13:16:15 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	ft_putendl_fd(char *s, int fd);
void	ft_lstnew(t_list **new, int content, int num);
void	ft_lstdelone(t_list **node);
void	ft_addfront(t_list **head, t_list *new);
int		ft_lstsize(t_list *head);
void	ft_swap(t_list *node);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
int		rra(t_list **head);
int		rrb(t_list **head);
int		rrr(t_list **a, t_list **b);
int		ra(t_list **head);
int		rb(t_list **head);
int		rr(t_list **a, t_list **b);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
void	ft_sort_three(t_list **list);
void	ft_sort(t_list **stack_a, t_list **stack_b, int argc);
void	ft_temporary_relocation(t_list **stack_a, t_list **stack_b, int i);
void	ft_assign_index(t_list **list, int argc);
void	ft_sort_five_or_less(t_list **stack_a, t_list **stack_b, int argc);
size_t	count_distance(t_list *stack_a, int i);
void	ft_return(t_list **stack_a, t_list **stack_b, int lstsize);
void	ft_push_to_stackb(t_list **stack_a,
			t_list **stack_b, int count, int num);
int		ft_arg_check(char **argv);
int		ft_is_sorted(t_list *list, int argc);
int		ft_is_duplicated(char **argv);
int		ft_is_integer(char **argv);

#endif