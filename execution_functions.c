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

void    execution_function(t_stack **head_a, t_stack **head_b, t_ind *index)
{
/*    t_stack *a;
    t_stack *b;

    b = *head_b;
    a = *head_a;*/
    while (*head_b)
    {
        initialize_costs_index(head_b, index);
        calculate_all_costs(head_a, head_b, index);
    /*    printf("*****************\n");
        printf("stack b is \n");
        display(*head_b);
        printf("stack a is \n");
        display(*head_a);
        printf("*****************\n");*/
        if (index->method_num == 1)
            execute_method1(index->index_a, index->index_b, head_a, head_b);
        else if (index->method_num == 2)
            execute_method2(index->index_a, index->index_b, head_a, head_b);
        else if (index->method_num == 3)
            execute_method3(index->index_a, index->index_b, head_a, head_b);
        else if (index->method_num == 4)
            execute_method4(index->index_a, index->index_b, head_a, head_b);
        push(head_a, head_b);
        printf("pa\n");
    }
    return ;
}

void    execute_method1(int index_a, int index_b, t_stack **head_a, t_stack **head_b)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < ft_min(index_a, index_b))
    {
        rotate_both_lst(head_a, head_b);
        i++;
    }
    while (j < ft_abs_value(index_a, index_b) && index_a != index_b)
    {
        if (index_a > index_b)
        {
            rotate(head_a);
            printf("ra\n");
        }
        else
        {
            rotate(head_b);
            printf("rb\n");
        }        
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
    a = ft_lstsize(*head_a) - index_a;
    b = ft_lstsize(*head_b) - index_b;
    while (i < ft_min(a, b))
    {
        rev_rotate_both_lst(head_a, head_b);
        i++;
    }
    while (j < ft_abs_value(a, b) && a != b)
    {
        if (b > a)
        {
            reverse_rotate(head_b);
            printf("rrb\n");
        }
        else
        {
            reverse_rotate(head_a);
            printf("rra\n");
        }
        j++;
    }
    return ;
}

void    execute_method3(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RA + RRB
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    size = ft_lstsize(*head_b) - index_b;
    while (i < index_a)
    {   
        rotate(head_a);
        printf("ra\n");
        i++;
    }
    while (j < size)
    {
        reverse_rotate(head_b);
        printf("rrb\n");
        j++;
    }
    return ;
}

void    execute_method4(int index_a, int index_b, t_stack **head_a, t_stack **head_b)// RB + RRA
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    size = ft_lstsize(*head_a) - index_a;
    while (i < index_b)
    {   
        rotate(head_b);
        printf("rb\n");
        i++;
    }
    while (j < size)
    {
        reverse_rotate(head_a);
        printf("rra\n");
        j++;
    }
    return ;
}