/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 01:15:16 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/28 01:15:18 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*repl;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	repl = ft_lstlast(*lst);
	repl->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack	*lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
