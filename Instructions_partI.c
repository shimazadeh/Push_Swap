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

void    swap(t_stack **lst)
{
    t_stack  *first;
    t_stack  *second;

    if (!(*lst) || !((*lst)->next))
        return ;
    first = ft_lstnew((*lst)->content);
    *lst = (*lst)->next;
    second = ft_lstnew((*lst)->content);
    *lst = (*lst)->next;
    ft_lstadd_front(lst, first);
    ft_lstadd_front(lst, second);
    return ;
}

void    push(t_stack **head_to, t_stack **head_from)
{
    t_stack  *to;
    t_stack  *from;
    t_stack  *temp;

    to = *head_to;
    from = *head_from;
    if (!from)
        return;
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
    return ;
}

void    rotate(t_stack **head_lst)
{
    t_stack  *first;
    t_stack  *last;
    t_stack  *stack;

    stack = *head_lst;
    if (!stack)
        return ;
    first = stack;
    stack = stack->next;
    last = stack;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    *head_lst = stack;
    return ;
}

void    reverse_rotate(t_stack **head_lst)
{
    t_stack  *prev;
    t_stack  *last;
    t_stack  *stack;

    stack = *head_lst;
    if (!stack)
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
    return ;
}
