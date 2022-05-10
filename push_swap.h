/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:53:58 by shabibol          #+#    #+#             */
/*   Updated: 2022/03/05 06:54:50 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
//# include "libft.h"

typedef struct s_stack
{
	int			content;
	struct s_stack	*next;
}t_stack;

//libft functions
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_issign(int c);
int		ft_isspace(int c);
int		ft_isnum(int c);
int 	ft_max(int a, int b);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);

///end of libft functions

int	ft_strlen_tab(char **tab);

char	**ft_free(char **dst, int i);
void    ft_free_lst(t_stack **lst);

//parsing functions
int 	all_error_checks(int size, char **arg);
int		allowed_char_check(char **arg);
int		dup_error_check(char **arg);
int 	multi_check(char *arg);

void	parsing(t_stack **lst, char **arg);
//end of parsing

void    swap(t_stack **lst);
void    push(t_stack **head_to, t_stack **head_from);
void    rotate(t_stack **head_lst);
void    reverse_rotate(t_stack **head_lst);
void    swap_both_lst(t_stack **a, t_stack **b);
void    rotate_both_lst(t_stack **a, t_stack **b);
void    rev_rotate_both_lst(t_stack **a, t_stack **b);

int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif
