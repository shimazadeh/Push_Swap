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

int sort_check(t_stack **head_a)// checks if the input is already sorted
{
    t_stack *a;
    t_stack *a_iteri;
    
    a = *head_a;
    while (a)
    {
        a_iteri = a->next;
        while (a_iteri)
        {
            if (a->content > a_iteri->content)
                return (1);
            a_iteri = a_iteri->next;
        }
        a = a->next;
    }
    return (0);
}

int calculate_cost_method1(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{//RR + RA/RB
/*    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < ft_min(index_a, index_b))
        i++;
    while (j < ft_abs_value(index_a, index_b) && index_a != index_b)
        j++;
    return (i + j);*/
    if (index_a < index_b)
        return (index_b);
    return (index_a);
}


int calculate_cost_method2(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{// RRR +RRA/RRB
    int i;
    t_stack *node_a;
    t_stack *node_b;

    i = 0;
    node_a = *head_a;
    node_b = *head_b;
    while (i < index_a)
    {
        node_a = node_a->next;
        i++;
    }
    i = 0;
    while (i < index_b)
    {
        node_b = node_b->next;
        i++;
    }
    if (ft_lstsize(node_a) < ft_lstsize(node_b))
        return (ft_lstsize(node_b));
    return (ft_lstsize(node_a));
    /*a = ft_lstsize(*head_a) - index_a;
    b = ft_lstsize(*head_b) - index_b;
    while (i < ft_min(a, b))
        i++;
    while (j < ft_abs_value(a, b) && a != b)
        j++;
    return (i + j);*/
}

int calculate_cost_method3(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{// RA + RRB

    int j;
    t_stack *node;

    node = *head_b;
    j = 0;
    while (j < index_b)
    {
        node = node->next;
        j++;
    }
    return (index_a + ft_lstsize(node));
}

int calculate_cost_method4(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{// RB + RRA
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < index_b)
        i++;
    while (j < (ft_lstsize(*head_a) - index_a))
        j++;
    return (i + j);
}