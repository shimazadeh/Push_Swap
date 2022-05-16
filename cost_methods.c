/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:20:57 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/12 19:21:10 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_check(t_stack **head_a, int element)// checks if stack a is ready to move element
{
    t_stack *a;
    int     first;
    int     last;

    a = *head_a;
    first = a->content;
    while (a->next)
        a = a->next;
    last = a->content;
    if (element > last && element <first)
        return (0);
    else
        return (1);
}

int calculate_cost_method1(int index_a, int index_b, t_stack **head_a, t_stack **head_b) //RR + RA/RB
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i <= ft_min(index_a, index_b))
    {
        rotate_both_lst(head_a, head_b);
        i++;
    }
    while (j < ft_abs_value(index_a, index_b) && index_a != index_b)
    {
        if (index_a > index_b)
            rotate(head_a);
        else
            rotate(head_b);
        j++;
    }
    return (i + j);
}


int calculate_cost_method2(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RRR +RRA/RRB
{
    int a;
    int b;
    int i;
    int j;

    i = 0;
    j = 0;
    a = ft_lstsize(head_a) - index_a;
    b = ft_lstsize(head_b) - index_b;
    while (i <= ft_min(a, b))
    {
        rev_rotate_both_lst(head_a, head_b);
        i++;
    }
    while (j < ft_abs_value(a, b) && a != b)
    {
        if (b > a)
            reverse_rotate(head_b);
        else
            reverse_rotate(head_a);
        j++;
    }
    return (i + j);
}

int calculate_cost_method3(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RA + RRB
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < index_a)
    {   
        rotate(head_a);
        i++;
    }
    while (j < (ft_lstsize(head_b) - index_b))
    {
        reverse_rotate(head_b);
        j++;
    }
    return (i + j);
}

int calculate_cost_method4(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RB + RRA
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < index_b)
    {   
        rotate(head_b);
        i++;
    }
    while (j < (ft_lstsize(head_a) - index_a))
    {
        reverse_rotate(head_a);
        j++;
    }
    return (i + j);
}