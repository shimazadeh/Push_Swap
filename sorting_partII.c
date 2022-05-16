/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_partI.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:28:27 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/12 19:28:29 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    calculate_all_costs(t_stack **head_a, t_stack **head_b)
{
    int       i;
    int       j;
    t_stack   *b;
    t_stack   *a;

    j = 0;
    b = *head_b;
    initialize_costs(head_b);
    while (b->content)
    {
        i = 0;
        a = *head_a
        while (a->content)
        {
            if (b->content > a->content && b->next->content < a->next->content)
            {
                b->cost1 = calculate_cost_method1(j, i, head_a, head_b);
                b->cost2 = calculate_cost_method2(j, i, head_a, head_b);
                b->cost3 = calculate_cost_method3(j, i, head_a, head_b);
                b->cost4 = calculate_cost_method4(j, i, head_a, head_b);
                //what if you update the index structure here...??
                //each content has two extra nodes index_a and index_b??
            }
            a = a->next;
            i++;
        }
        j++;
        b = b->next;
    }
    return ;
}

t_stack lowest_cost_element(t_stack  **head_b)
{
    int     cost;
    int     temp1;
    t_stack *res;

    cost = 2147483647;
    while (head_b->content)
    {
        if (head_b->cost1 < head_b->cost2)
            temp1 = head_b->cost1;
        else
            temp1 = head_b->cost2;
        if (head_b->cost3 < temp1)
            temp1 = head_b->cost3;
        if (head_b->cost4 < temp1)
            temp1 = head_b->cost4;
        if (temp1 < cost)
        {    
            cost = temp1;
            res = *head_b;
        }
        head_b = head_b->next;
    }
    return (res);
}

int lowest_cost(t_stack  **head_b)
{
    int     cost;
    int     temp1;

    cost = 2147483647;
    while (head_b->content)
    {
        if (head_b->cost1 < head_b->cost2)
            temp1 = head_b->cost1;
        else
            temp1 = head_b->cost2;
        if (head_b->cost3 < temp1)
            temp1 = head_b->cost3;
        if (head_b->cost4 < temp1)
            temp1 = head_b->cost4;
        if (temp1 < cost)
            cost = temp1;
        head_b = head_b->next;
    }
    return (cost);
}

void    initialize_costs(t_stack **head_b)
{
    t_stack *b;

    b = *head_b;
    while (b->content)
    {
        b->cost1 = 0;
        b->cost2 = 0;
        b->cost3 = 0;
        b->cost4 = 0;
        b = b->next;
    }
    return ;
}