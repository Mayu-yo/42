#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int		value;
	int		index;
	struct s_list *prev;
	struct s_list *next;
}	t_list;

void	ft_putendl_fd(char *s, int fd);
void	ft_lstnew(t_list **new, int content, int num);
void	ft_lstdelone(t_list **node);
void	ft_addfront(t_list **head, t_list *new);
int		ft_lstsize (t_list *head);
void	ft_swap (t_list *node);
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
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_sort_three(t_list **list);
void	ft_sort(t_list **stack_a, t_list **stack_b, int argc);
void ft_assign_index(t_list **list, int argc);
void ft_sort_six_or_less(t_list **stack_a, t_list **stack_b, int argc);
size_t count_distance(t_list *stack_a, int i);
void ft_sort(t_list **stack_a, t_list **stack_b, int stack_size);
void ft_return(t_list **stack_a, t_list **stack_b, int lstsize);
void ft_push_to_stackb(t_list **stack_a, t_list **stack_b, int count, int num);

#endif