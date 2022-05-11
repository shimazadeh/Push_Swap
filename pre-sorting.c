/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre-sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:16:39 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/10 17:16:41 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void    initialize_ranking(t_stack  **head_lst)
{
    int value;

    value = 1;
    while ((*head_lst))
    {
        (*head_lst)->rank = value;
        (*head_lst) = (*head_lst)->next;
        value++;
    }
    return ;
}

void    pre_sorting(t_stack  **head_lst)
{
    t_stack *start;
    t_stack *compare;
    t_stack *stack;
    int     temp;
    int     a;
    int     b;

    start = *head_lst;
    compare = *head_lst;
    stack = *head_lst;
    compare = compare->next;
    
    initialize_ranking(head_lst);
    while (start)
    {
        a = start->content;
        compare = start->next;
        while (compare)
        {
            b = compare->content;
            if (a > b)
            {
                temp = start->rank;
                start->rank = compare->rank;
                compare->rank = temp;
            }
            compare = compare->next;
        }
        start = start->next;
    }
    *head_lst = stack;
    return ;
}

*/
