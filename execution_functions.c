/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:51:51 by shabibol          #+#    #+#             */
/*   Updated: 2022/05/16 19:51:52 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    execution_function(t_stack **head_a, t_stack **head_b)
{
    t_stack *a;
    t_stack *b;
    t_stack *element;
    t_ind   *index;

    b = *head_b;
    b_copy = *head_b;
    a = *head_a;
    a_copy = *head_a;
    while (b)
    {
        calculate_all_costs(head_a, head_b);
        element = lowest_cost_element(head_b);
        min = lowest_cost(head_b);
        update_index(head_a, head_b, index);
        if (element->cost1 == min)
            execute_method1(index->index_a, index->index_b, head_a, head_b);
        if (element->cost2 == min)
            execute_method2(index->index_a, index->index_b, head_a, head_b);
        if (element->cost3 == min)
            execute_method3(index->index_a, index->index_b, head_a, head_b);
        if (element->cost4 == min)
            execute_method4(index->index_a, index->index_b, head_a, head_b);
    }
    return ;
}

void    update_index(t_stack **head_a, t_stack **head_b, t_ind index)
{
    int i;
    int j;
    t_stack *b_copy;
    t_stack *a_copy;

    a_copy = *head_a;
    b_copy = *head_b;
    i = 0;
    while (b_copy->content)
    {
        j = 0;
        while (a_copy->content)
        {
            if (b_copy->content > a_copy->content && b_copy->next->content < a_copy->next->content)
            {
                index->index_a = j;
                index->index_b = i;
                return ;
            }
            j++;
        }
        i++;
    }
    return ;
}

void    execute_method1(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
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
    return ;
}

void    execute_method2(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RRR +RRA/RRB
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
    return ;
}

void    execute_method3(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RA + RRB
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
    return ;
}

void    execute_method4(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RB + RRA
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
    return ;
}