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
    t_list *lst;

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
*/
    swap_lst(&lst);

    printf("after swap_a:\n");   
    while (lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }
    ft_free_lst(&lst);
    return (0);
}