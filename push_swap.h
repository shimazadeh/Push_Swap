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

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}t_list;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

void	parsing(t_list *lst, char **arg);
size_t	ft_strlen(const char *s);

int     ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_list *lst, t_list *new);
void	ft_lstadd_front(t_list *lst, t_list *new);


#endif
