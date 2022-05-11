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


int main(int argc, char **argv)
{
    t_stack     *lst;
    t_struct    *tab;
    if (all_error_checks(argc, argv) == 1)
        {
            write(1, "Error\n", 6);
            return (0);
        }
    else if (all_error_checks(argc, argv) == 2)
        return (0);
    lst = NULL;
    parsing(&lst, argv);
//  printf("the original list:\n");   
/*    while (lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }

    swap_lst(&lst);
    rotate(&lst);
    reverse_rotate(&lst);

    printf("rankings:\n");   
    while (lst)
    {
        printf("%d\n", lst->rank);
        lst = lst->next;
    }
*/
    initialize_tab(tab);
    find_min_max(&lst, tab);
    find_median(&lst, tab);
    printf("the min is %d, the max is %d, the median is %d\n", tab->min, tab->max, tab->median);
    ft_free_lst(&lst);
    return (0);
}