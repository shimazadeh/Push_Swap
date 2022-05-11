/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:11:37 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/10 15:11:39 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    return (0);
}

void    initialize_cost(t_stack  **head_lst)
{
    int value;

    value = -1;
    while ((*head_lst))
    {
        (*head_lst)->cost1 = value;
        (*head_lst)->cost2 = value;
        (*head_lst)->cost3 = value;
        (*head_lst)->cost4 = value;
        (*head_lst) = (*head_lst)->next;
    }
    return ;
}


t_struct    *initialize_tab(t_struct  *tab)
{
    tab->min = -1;
    tab->max = -1;
    tab->median = -1;
    return (tab);
}

void    find_min_max(t_stack **head_lst, t_struct *tab)
{
    int temp;
    t_stack *stack;


    stack = *head_lst;
    tab->min = stack->content;
    stack = stack->next;
    tab->max = stack->content;
    stack = stack->next;
    
    while(stack)
    {
        temp = stack->content;
        if (tab->min > temp)
            tab->min = temp;
        if (tab->max < temp)
            tab->max = temp;
        stack = stack->next;
    }
    return ;
}

void    find_median(t_stack **head_lst, t_struct *tab)
{
    t_stack *start;
    t_stack *compare;
    t_stack *stack;
    int     a;
    int     b;
    int     size;
    int     count;

    start = *head_lst;
    compare = *head_lst;
    stack = *head_lst;
    compare = compare->next;
    size = ft_lstsize(start);
    while (start)
    {
        count = 0;
        a = start->content;
        compare = *head_lst;
        while (compare)
        {
            b = compare->content;
            if (b < a)
                count++;
            compare = compare->next;
        }
        if (count == size/2)
        {
            tab->median = start->content;
            *head_lst = stack;
            return ;
        }
        start = start->next;
    }
    *head_lst = stack;
    return ;
}