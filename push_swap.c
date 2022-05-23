/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shabibol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:49:59 by shabibol          #+#    #+#             */
/*   Updated: 2022/04/24 15:50:03 by shabibol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    display(t_stack *b)
{
    while (b)
    {
        printf("the content is: %d\n", b->content);
        /*
        printf("the cost1 is: %d\n", b->cost1);
        printf("the cost2 is: %d\n", b->cost2);
        printf("the cost3 is: %d\n", b->cost3);
        printf("the cost4 is: %d\n", b->cost4);*/
        printf("\n");
        b = b->next;
    }
}

int main(int argc, char **argv)
{
    t_stack     *a;
    t_struct    *tab;
    t_stack     *b;
    t_ind       *index;

    a = (t_stack *)malloc(sizeof(t_struct));
    b = (t_stack *)malloc(sizeof(t_struct));
    tab = (t_struct *)malloc(sizeof(t_struct));
    index = (t_ind *)malloc(sizeof(t_ind));
    a = NULL;
    b = NULL;
    if (all_error_checks(argc, argv) == 1)
        {
            write(1, "Error\n", 6);
            return (0);
        }
    else if (all_error_checks(argc, argv) == 2)
        return (0);
    parsing(&a, argv);
    if (sort_check(&a) == 0)
        return (0);
    initialize_tab(tab);
    find_min_max(&a, tab);
    find_median(&a, tab);
/*
    printf("the min is %d, the max is %d, the median is %d\n", tab->min, tab->max, tab->median);
        
    printf("the content of stack a before move:\n");
    display(a);
*/
    move_to_stack_b(&a, &b, tab);
/*
    printf("the content of stack a after sorting:\n");
    display(a);
    printf("the content of stack b after sorting:\n");
    display(b);
*/
    execution_function(&a, &b, index);
/*
    printf("the stack a after execution:\n");
    display(a);
    printf("the stack b after execution:\n");
    display(b);
*/
    final_check(&a, tab);
    ft_free_lst(&a);
    ft_free_lst(&b);
    free(tab);
    free(index);
    return (0);
}