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
        printf("%d\n", b->content);
        b = b->next;
    }
}

int main(int argc, char **argv)
{
    t_stack     *a;
    t_struct    *tab;
    t_stack     *b;

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
//    execution_function(&a, &b);
    printf("the a stack before:\n");
    display(a);

    printf("the b stack before:\n");
    display(b);

    execute_method1(0, 1, &a, &b);
    printf("the a stack front to back:\n");
    display(a);

    printf("the b stack after:\n");
    display(b);

    ft_free_lst(&a);
    return (0);
}