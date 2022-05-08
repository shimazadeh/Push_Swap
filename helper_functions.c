/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:25:20 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/05 19:25:22 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

void    ft_free_lst(t_list **lst)
{
    t_list  *tmp;
    if(!*lst)
        return;
    while (*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
}