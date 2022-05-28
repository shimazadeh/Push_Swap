/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_partI.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:50:00 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/10 12:50:12 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst, char *str)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*lst) || !((*lst)->next))
		return ;
	first = ft_lstnew((*lst)->content);
	*lst = (*lst)->next;
	second = ft_lstnew((*lst)->content);
	*lst = (*lst)->next;
	ft_lstadd_front(lst, first);
	ft_lstadd_front(lst, second);
	ft_printf("%s\n", str);
	return ;
}

void	push(t_stack **head_to, t_stack **head_from, char *str)
{
	t_stack	*to;
	t_stack	*from;
	t_stack	*temp;

	to = *head_to;
	from = *head_from;
	if (!from)
		return ;
	temp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = temp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		temp->next = to;
		*head_to = temp;
	}
	ft_printf("%s\n", str);
	return ;
}

void	rotate(t_stack **head_lst, char *str)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*stack;

	stack = *head_lst;
	if (!stack || ft_lstsize(*head_lst) == 1)
		return ;
	first = stack;
	stack = stack->next;
	last = stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head_lst = stack;
	if (ft_strlen(str))
		ft_printf("%s\n", str);
	return ;
}

void	reverse_rotate(t_stack **head_lst, char *str)
{
	t_stack	*prev;
	t_stack	*last;
	t_stack	*stack;

	stack = *head_lst;
	if (!stack || ft_lstsize(*head_lst) == 1)
		return ;
	last = stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = stack;
	prev->next = NULL;
	*head_lst = last;
	if (ft_strlen(str))
		ft_printf("%s\n", str);
	return ;
}
