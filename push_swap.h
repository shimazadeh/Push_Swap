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

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}t_list;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_issign(int c);
int		ft_isspace(int c);
int		ft_isnum(int c);
int 	ft_max(int a, int b);

char	**ft_free(char **dst, int i);
void    ft_free_lst(t_list **lst);

int 	all_error_checks(int size, char **arg);
int		allowed_char_check(char **arg);
int		dup_error_check(char **arg);
int 	multi_check(char *arg);

void    swap_lst(t_list **lst);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

char	**ft_split(char const *s, char c);

void	parsing(t_list **lst, char **arg);

size_t	ft_strlen(const char *s);

int     ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);


#endif
