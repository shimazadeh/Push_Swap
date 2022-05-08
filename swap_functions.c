/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:21:36 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/08 18:21:38 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_lst(t_list **lst)
{
    int     size;
    t_list  *first;
    t_list  *second;

    size = ft_lstsize(*lst);
    if (size < 2)
        return ;
    first = ft_lstnew((*lst)->content);
    *lst = (*lst)->next;
    second = ft_lstnew((*lst)->content);
    *lst = (*lst)->next;
    ft_lstadd_front(lst, first);
    ft_lstadd_front(lst, second);
    return ;
}

void    swap_both_lst(t_list **a, t_list **b)
{
    swap_lst(&a);
    swap_lst(&b);
    return ;
}

void    push_lst(t_list **a, t_list **b)
{
    int     size_b;
    t_list  *first;

    size_b = ft_lstsize(*b);
    if (!size_b)
        return;
    first = ft_lstnew((*b)->content);
    ft_lstadd_front(a, first);
    ft_lst_remove(b);
}

void    rotate(t_list **a)
{
    int     size;
    t_list  *temp;

    size = ft_lstsize(*a);
    if (size < 2)
        return ;
    temp = ft_lstnew((*a)->content);
    ft_lstadd_back(a, temp);
    ft_lst_remove(a);
}

void    reverse_rotate(t_list **a)
{
    int     size;
    int     i;
    t_list  *temp;

    i = 1;
    size = ft_lstsize(*a);
    if (size < 2)
        return ;
    while (i < size)
    {
        *a = (*a)->next;
        i++;
    }
    temp = ft_lstnew((*a)->content);
    ft_lstadd_front(a, temp);
}