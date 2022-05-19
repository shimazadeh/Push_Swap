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
        printf("the cost1 is: %d\n", b->cost1);
        printf("the cost2 is: %d\n", b->cost2);
        printf("the cost3 is: %d\n", b->cost3);
        printf("the cost4 is: %d\n", b->cost4);
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
    tab = (t_struct *)malloc(sizeof(t_struct));
    if (all_error_checks(argc, argv) == 1)
        {
            write(1, "Error\n", 6);
            return (0);
        }
    else if (all_error_checks(argc, argv) == 2)
        return (0);
    a = NULL;
    b = NULL;
    parsing(&a, argv);
    initialize_tab(tab);
    find_min_max(&a, tab);
    find_median(&a, tab);
    printf("the min is %d, the max is %d, the median is %d\n", tab->min, tab->max, tab->median);
    
    move_to_stack_b(&a, &b, tab);
    printf("the a stack before:\n");
    display(a);

    printf("the b stack before:\n");
    display(b);

    printf("\n");
    printf("\n");

    execution_function(&a, &b, index);
    printf("the a stack after execution:\n");
    display(a);

    printf("the b stack after execution:\n");
    display(b);

    ft_free_lst(&a);
    return (0);
}