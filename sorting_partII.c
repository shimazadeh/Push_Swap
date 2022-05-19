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

void    calculate_all_costs(t_stack **head_a, t_stack **head_b, t_ind *index)
{
    int         i;
    int         j;
    t_stack     *b;
    t_stack     *a;

    j = 0;
    b = *head_b;
    while (b)
    {
        i = 0;
        a = *head_a;
        if (b->content < a->content)
        {
            while (a->next && a->content < a->next->content)
            {
                a = a->next;
                i++;
            }
            if (a->next)
            {
                a = a->next;
                while (a && b->content > a->content)
                {
                    a = a->next;
                    i++;
                }
                if(!a)
                    i = 0;
            }
            else if (!a->next && b->content < a->content)
                i = 0;
        }
        else if (b->content > a->content)
        {
            while (a->next && b->content > a->content && a->content < a->next->content)
            {
                a = a->next;
                i++;
            }
            if (!a->next && b->content > a->content)
                i = 0;
        }
        b->cost1 = calculate_cost_method1(j, i, head_a, head_b);
        b->cost2 = calculate_cost_method2(j, i, head_a, head_b);
        b->cost3 = calculate_cost_method3(j, i, head_a, head_b);
        b->cost4 = calculate_cost_method4(j, i, head_a, head_b);
        update_lowest_cost(b, index, i, j);
        j++;
        b = b->next;
    }
    return ;
}

void    update_lowest_cost(t_stack *head_b, t_ind *index, int index_a, int index_b)
{
    if (head_b->cost1 < index->lowest_cost)
    {
        index->lowest_cost = head_b->cost1;
        index->method_num = 1;
        index->index_b = index_b;
        index->index_a = index_a;
    }
    if (head_b->cost2 < index->lowest_cost)
    {
        index->lowest_cost = head_b->cost2;
        index->method_num = 2;
        index->index_b = index_b;
        index->index_a = index_a;
    }
    if (head_b->cost3 < index->lowest_cost)
    {
        index->lowest_cost = head_b->cost3;
        index->method_num = 3;
        index->index_b = index_b;
        index->index_a = index_a;
    }
    if (head_b->cost4 < index->lowest_cost)
    {
        index->lowest_cost = head_b->cost4;
        index->method_num = 4;
        index->index_b = index_b;
        index->index_a = index_a;
    }
    return ;
}

void    initialize_costs_index(t_stack **head_b, t_ind *index)
{
    t_stack *b;

    b = *head_b;
    while (b)
    {
        b->cost1 = -1;
        b->cost2 = -1;
        b->cost3 = -1;
        b->cost4 = -1;
        b = b->next;
    }
    index->lowest_cost = 2147483647;
    index->method_num = -1;
    index->index_a = -1;
    index->index_b = -1;
    return ;
}
