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

int calculate_cost_method1(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{
    int     diff;
    int     small_index;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (index_a > index_b)
    {
        small_index = index_b;
        diff = index_a - index_b;
    }
    else
    {
        small_index = index_a;
        diff = index_b - index_a;
    }
    while (i <= small_index)
    {
        rotate_both_lst(head_a, head_b);
        i++;
    }
    while (j < diff && index_a != index_b)
    {
        if (index_a > index_b)
            rotate(head_a);
        else
            rotate(head_b);
        j++;
    }
    return (i + j);
}


int calculate_cost_method2(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{
    int     diff;
    int     small_index;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (index_a > index_b)
    {
        small_index = index_b;
        diff = index_a - index_b;
    }
    else
    {
        small_index = index_a;
        diff = index_b - index_a;
    }
    while (i <= small_index)
    {
        rotate_both_lst(head_a, head_b);
        i++;
    }
    while (j < diff && index_a != index_b)
    {
        if (index_a > index_b)
            rotate(head_a);
        else
            rotate(head_b);
        j++;
    }
    return (i + j);
}