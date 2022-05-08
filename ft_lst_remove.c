/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:56:28 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/08 23:56:30 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lst_remove(t_list **lst)
{
    t_list  *temp;
    t_list  **new_lst;

    if (!lst)
        return ;
    *lst = (*lst)->next;
    while (lst)
    {
        temp = ft_lstnew((*lst)->content);
        ft_lstadd_back(new_lst, temp);
        (*lst) = (*lst)->next;
    }
    
}
